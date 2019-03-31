<?php
include("../ft_log.php");
session_start();
if (!file_exists("../private"))
    mkdir("../private");
$users_db = array();
if (file_exists("../private/users"))
    $users_db = array_filter(unserialize(file_get_contents("../private/users")));
if ($users_db[$_SESSION['login']]['rights'] != -2) {
    header("HTTP/1.0 403 Forbidden");
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}
if (isset($_GET['delete'])) {
    if ($users_db[$_GET['delete']]['rights'] != -2) {
        unset($users_db[$_GET['delete']]);
        file_put_contents("../private/users", serialize(array_filter($users_db)), LOCK_EX);
    }
    header("Location: user.php");
}
else {
    $error_image = "respond.jpg";
    if (isset($_POST['login'], $_POST['passwd'], $_POST['rpasswd'], $_POST['submit'])) {
        if ($_POST['rpasswd'] !== $_POST['passwd'] || $_POST['submit'] !== 'OK') {
            $error_message = ($_POST['submit'] !== 'OK') ? "Mauvaise requette !" : "Mot de passes non identiques !";
            $error_image = ($_POST['submit'] !== 'OK') ? "respond.jpg" : "brain_not_found.jpg";
        } else if ($_POST['passwd'] === '' || $_POST['login'] === '') {
            $error_message = "Le mot de passe et le login ne peuvent pas être vides !";
            $error_image = "empty_pass.jpg";
        } else {
            if (!file_exists("../private"))
                mkdir("../private");
            if (isset($users_db[$_POST['login']])) {
                $error_message = "Le pseudo existe déjà !";
                $error_image = "Baby-Clone.jpg";
            } elseif ($error_message == '') {
                $user_credential['passwd'] = password_hash($_POST['passwd'], PASSWORD_BCRYPT);
                $user_credential['rights'] = -1;
                $users_db[$_POST['login']] = $user_credential;
                file_put_contents("../private/users", serialize($users_db), LOCK_EX);
                header("Location: /admin/user.php");
            }
        }
    }
}
?>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Admin/User</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="../css/admin.css"/>
    <link rel="shortcut icon" href="../img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="../img/favicon.ico" type="image/x-icon">
</head>
<body bgcolor="#2e3131" style="margin: 0;">
<div class="head">
    <a href="/index.php"><h1 class="headtitle">El Marketo</h1></a>
    <div class="cont">
        <a href="/admin/index.php">
            <button class="cart">Home admin</button>
        </a>
        <a href="/admin/orders.php">
            <button class="cart">Orders menu</button>
        </a>
        <a href="/admin/cat.php">
            <button class="cart">Catégorie menu</button>
        </a>
        <a href="/logout.php">
            <button class="logout">Se déconnecter</button>
        </a>
    </div>
</div>
<div class="admintab">
    <form method="post" action="/admin/user.php">
        <h2 class="texte">Créer un utilisateur</h2>
        <input placeholder="Votre pseudo" type="text" name="login" size="27" class="info">
        <input placeholder="Entrez le mot de passe" type="password" name="passwd" size="27" class="info">
        <input placeholder="Entrez le mot de passe à nouveau" type="password" name="rpasswd" size="27"
               class="info">
        <button type="submit" value="OK" name="submit" class="post">Créer</button>

    </form></div>
<hr>
<div class="admintab">
    <div>
            <h2 class="texte">Supprimez un utilisateurs</h2>
    </div>
</div>
<?php
$users_db = array_filter($users_db, function($R) {return( $R['rights'] !== -2);});
if (count($users_db)) { ?>
<div class="admin-tab-center">
    <table>
        <tbody>
        <?php
        foreach ($users_db as $id => $article) {
            if ($article['rights'] !== -2) { ?>
                <tr>
                    <td class="admintab-texte" align="center"><?= htmlspecialchars($id) ?></td>
                    <td class="admintab-texte" align="center"><a href="/admin/user.php?delete=<?= urlencode($id) ?>">❌</a></td>
                </tr>
                <?php
            }}
        }
        ?>
        </tbody>
    </table>
</div>
<footer> © Copyright 2019 All rights reserved to agissing and kemartin.</footer>
</body>
</html>
