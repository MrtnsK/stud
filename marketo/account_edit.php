<?php
include("check_log.php");
session_start();
if (!check_log()){
    header("Location: index.php");
    exit;
}

if (isset($_POST['submit'], $_POST['oldpasswd'], $_POST['newpasswd']) && !empty($_POST['newpasswd']) && $_POST['submit'] == "OK") {
    if (!file_exists("/private"))
        mkdir("/private");
    $users_db = array();
    if (file_exists("private/users"))
        $users_db = unserialize(file_get_contents("private/users"));
    if (isset($users_db[$_POST['login']]) && $_POST['login'] === $_SESSION['login']) {
        if (password_verify($_POST['oldpasswd'], $users_db[$_POST['login']]['passwd'])) {
            $users_db[$_POST['login']]['passwd'] = password_hash($_POST['newpasswd'], PASSWORD_BCRYPT);
            $f = fopen("private/users", "w");
            flock($f, LOCK_EX);
            file_put_contents("private/users", serialize(array_filter($users_db)));
            flock($f, LOCK_UN);
            fclose($f);
        } else {
            header("Location: account_edit.php?error=pass");
            exit ();
        }
    } else {
        header("Location: account_edit.php?error=login");
        exit ();
    }
    header("Location: index.php");
}
?>
<html>
<head>
    <meta charset="UTF-8">
    <title>Modifier mon compte</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/log.css"/>
    <link rel="shortcut icon" href="/img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="/img/favicon.ico" type="image/x-icon">
    <?php if ($_GET['error'] === 'pass') { ?>
        <style>
            .pass {
                border-color: red;
            }
        </style>
    <?php } if ($_GET['error'] === 'login') { ?>
        <style>
            .login {
                border-color: red;
            }
        </style>
    <?php } ?>
</head>
<body bgcolor="#2e3131">
<div class="login-page">
    <div class="box">
        <p class="title">Modifier mon mot de passe</p>
        <div>
            <form method="post" action="account_edit.php">
                <h2 class="font"></h2>
                <input value="<?=$_SESSION['login']?>" type="text" name="login" size="27" class="font login">
                <input placeholder="Entrez l'ancien mot de passe" type="password" name="oldpasswd" size="27"
                       class="font pass">
                <input placeholder="Entrez le nouveau mot de passe" type="password" name="newpasswd" size="27"
                       class="font pass">
                <button type="submit" value="OK" name="submit" class="button">Modifier</button>
            </form>
            <a href="/index.php">
                <button class="button" style="margin-top: -16px;" id="mv">Retour</button>
            </a>
        </div>
    </div>
</div>
<footer> © Copyright 2019 All rights reserved to agissing and kemartin.</footer>
</body>
</html>