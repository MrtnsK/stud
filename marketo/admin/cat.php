<?php
include("../ft_log.php");
session_start();

if (!file_exists("../private"))
    mkdir("../private");

$cat = array();
if (file_exists("../private/categorie"))
    $cat = array_filter(unserialize(file_get_contents("../private/categorie")));

$users_db = array();
if (file_exists("../private/users"))
    $users_db = array_filter(unserialize(file_get_contents("../private/users")));

$article_db = array();
if (file_exists("../private/articles"))
    $article_db = array_filter(unserialize(file_get_contents("../private/articles")));

if ($users_db[$_SESSION['login']]['rights'] != -2) {
    header("HTTP/1.0 403 Forbidden");
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}

if (isset($_POST['cat']) && $_POST['submit'] == "OK") {
    array_push($cat,$_POST['cat']);
    file_put_contents("../private/categorie", serialize(array_filter($cat)), LOCK_EX);
}
if (isset($_GET['delete'])) {
    $article_db = array_filter($article_db, function ($art) use ($cat) {
        return ($art['categorie'] != $cat[$_GET['delete']]);
    });
    unset($cat[$_GET['delete']]);
    file_put_contents("../private/categorie", serialize(array_filter($cat)), LOCK_EX);
    file_put_contents("../private/articles", serialize(array_filter($article_db)), LOCK_EX);
    header("Location: cat.php");
}
?>
<html>
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
            <a href="/admin/index.php">
                <button class="cart">Home admin</button>
            </a>
            <a href="/admin/user.php">
                <button class="cart">Users menu</button>
            </a>
            <a href="/logout.php">
                <button class="logout">Se déconnecter</button>
            </a>
        </div>
    </div>
    <div class="admintab" style="flex-direction: column">
        <h2 class="texte">Ajoutez ou supprimez une catégorie</h2>
        <form method="post" action="/admin/cat.php" style="display: flex;margin: auto;">
            <input placeholder="Nouvelle catégorie" type="text" name="cat" size="27" id="cat">
            <button type="submit" value="OK" name="submit" class="post">Créer</button>
        </form>
    </div>
    <?php
    if (count($cat)) { ?>
    <div class="admin-tab-center">
        <table>
            <tbody>
            <?php
            foreach ($cat as $id => $article) { ?>
                    <tr>
                        <td class="admintab-texte" align="center"><?= htmlspecialchars($article) ?></td>
                        <td class="admintab-texte" align="center"><a href="/admin/cat.php?delete=<?= urlencode($id) ?>">❌</a></td>
                    </tr>
                    <?php
                }
            }
            ?>
            </tbody>
        </table>
    </div>
</body>
</html>