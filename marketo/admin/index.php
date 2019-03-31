<?php
session_start();
if (!file_exists("../private"))
    mkdir("../private");
$fake_db = array();
if (file_exists("../private/users"))
    $fake_db = array_filter(unserialize(file_get_contents("../private/users")));

if ($fake_db[$_SESSION['login']]['rights'] !== -2) {
    header("HTTP/1.0 403 Forbidden");
    echo "<title>El Marketo</title>";
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}

$cat_db = array();
if (file_exists("../private/categorie"))
    $cat_db = array_filter(unserialize(file_get_contents("../private/categorie")));

$articles_db = array();
if (file_exists("../private/articles"))
    $articles_db = array_filter(unserialize(file_get_contents("../private/articles")));

if (isset($_GET['delete'])) {
    if (isset($articles_db[$_GET['delete']], $articles_db[$_GET['delete']]['image'])) {
        unlink($articles_db[$_GET['delete']]['image']);
        unset($articles_db[$_GET['delete']]);
        array_push($articles_db, $tab);
        file_put_contents("../private/articles", serialize(array_filter($articles_db)), LOCK_EX);
    }
    header("Location: /admin");
} elseif (!empty($_FILES["image"]["tmp_name"]) && isset($_FILES['image'], $_POST['price'], $_POST['description'], $_POST['name'], $_POST['categorie'])
    && $_POST['submit'] == "OK" && $_POST['price'] >= 0) {
    $tab['name'] = substr($_POST['name'], 0, 30);
    $tab['price'] = substr($_POST['price'], 0, 7);
    $tab['description'] = substr($_POST['description'], 0, 100);
    $tab['categorie'] = $_POST['categorie'];
    //FILE UPLOAD
    if (!file_exists("../img/article"))
        mkdir("../img/article");
    $target_dir = "../img/article/";
    $target_file = $target_dir . basename($_FILES["image"]["name"]);
    $i = 1;
    while (file_exists($target_file)) {
        $split = explode(".", basename($_FILES["image"]["name"]));
        $extension = array_pop($split);
        $target_file = $target_dir . join(".", $split) . $i++ . ".$extension";
    }
    $imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
    if (!getimagesize($_FILES["image"]["tmp_name"]))
        exit ("<h1 align='center'>Désolé, une erreur est survenue pendant le téléchargement.</h1>");
    if ($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
        && $imageFileType != "gif") {
        exit ("<h1 align='center'>Désolé, une erreur est survenue pendant le téléchargement.</h1>");
        $uploadOk = 0;
    }
    if (move_uploaded_file($_FILES["image"]["tmp_name"], $target_file)) {
        $tab['image'] = $target_file;
    } else {
        exit ("<h1 align='center'>Désolé, une erreur est survenue pendant le téléchargement.</h1>");
    }
    /////
    array_push($articles_db, $tab);
    file_put_contents("../private/articles", serialize($articles_db), LOCK_EX);
    header("Location: /admin");
} elseif (isset($_POST['submit'])) {
    $error_message = "Veuillez vérifier les champs !";
    $error_image = "respond.jpg";
}
?>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <title>Admin</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="../css/admin.css" />
    <link rel="shortcut icon" href="../img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="../img/favicon.ico" type="image/x-icon">
</head>

<body bgcolor="#2e3131" style="margin: 0;">
    <div class="head">
        <a href="/index.php">
            <h1 class="headtitle">El Marketo</h1>
        </a>
        <div class="cont">
            <a href="/admin/orders.php">
                <button class="cart">Orders menu</button>
            </a>
            <a href="/admin/cat.php">
                <button class="cart">Catégorie menu</button>
            </a>
            <a href="/admin/user.php">
                <button class="cart">Users menu</button>
            </a>
            <a href="/logout.php">
                <button class="logout">Se déconnecter</button>
            </a>
        </div>
    </div>
    <?php if (!isset($error_message)) { ?>
    <div class="admintab">
        <div>
            <form method="post" action="../admin/index.php" enctype="multipart/form-data">
                <h2 class="texte">Ajoutez un article</h2>
                <div id="toolb">
                    <input placeholder="name" type="text" name="name" size="27" class="info" maxlength="30">
                    <input placeholder="description" type="text" name="description" size="27" class="info"
                        maxlength="100">
                    <input placeholder="price" type="number" name="price" size="27" class="info" min="0.00"
                        max="99999.99" step="0.01">
                    <section>
                        <div class="select-group">
                            <select name="categorie">
                                <?php if (!empty($cat_db)) { foreach ($cat_db as $cat) { ?>
                                <option><?= htmlspecialchars($cat) ?></option>
                                <?php  }} ?>
                            </select>
                            <div class="arrow">▼</div>
                        </div>
                    </section>
                    <input type="file" name="image" size="27" class="info" id="image">
                    <button type="submit" value="OK" name="submit" class="post">Créer</button>
                </div>
            </form>
        </div>
    </div>
    <?php if (count($articles_db)) { ?>
    <div class="admin-tab-center">
        <table>
            <tbody>
                <?php foreach ($articles_db as $id => $article) { ?>
                <form method="post" action="../admin/edit.php" enctype="multipart/form-data">
                    <tr>
                        <td align="center">
                            <input class="admintab-texte" value="<?= htmlspecialchars($article['name']) ?>" name="name">
                        </td>
                        <td align="center">
                            <input class="admintab-texte" value="<?= htmlspecialchars($article['description']) ?>"
                                name="description">
                        </td>
                        <td align="center">
                            <input type="number" name="price" min="0.00" max="99999.99" step="0.01"
                                class="admintab-texte" value="<?= htmlspecialchars($article['price']) ?>">
                        </td>
                        <td align="center">
                            <section>
                                <div>
                                    <select name="categorie" id="noborder">
                                        <option selected="selected"><?= htmlspecialchars($article['categorie']) ?>
                                        </option>
                                        <?php $sort_cat = array_filter($cat_db, function ($catt) use ($article) {return ($catt != $article['categorie']);}); if (!empty($sort_cat)) { foreach ($sort_cat as $cat) { ?>
                                        <option><?= htmlspecialchars($cat) ?></option>
                                        <?php  }} ?>
                                    </select>
                                </div>
                            </section>
                        </td>
                        <td align="center">
                            <label for="imageedit">
                                <img src="<?= htmlspecialchars($article['image']) ?>" />
                            </label>
                            <input style="display: none;" type="file" id="imageedit" name="image">
                        </td>
                        <td align="center">
                            <a href="/admin/index.php?delete=<?= urlencode($id) ?>">❌</a>
                        </td>
                        <td align="center">
                            <input type="hidden" name="article_id" value="<?= $id ?>">
                            <button type="submit" name="submit" value="OK" id="editbutton">Editer</button>
                        </td>
                    </tr>
                </form>
                <?php }} ?>
            </tbody>
        </table>
    </div>
    <?php }else{ ?>
    <h1 align='center'><?= $error_message ?></h1>
    <p align='center'><img src='/img/<?= $error_image ?>' alt="error"></p>
    <?php } ?>
    <footer> © Copyright 2019 All rights reserved to agissing and kemartin.</footer>
</body>

</html>