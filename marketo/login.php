<?php
    session_start();
    include('check_login.php');
    include('ft_log.php');
    $error_image = "respond.jpg";
    if (isset($_POST['login'], $_POST['passwd'], $_POST['submit'])) {
        if ($_POST['submit'] !== 'OK') {
            $error_message = "Mauvaise requette !";
            $error_image = "respond.jpg";
        }
        elseif (check_pair($_POST['login'], $_POST['passwd'])) {
            log_user($_POST['login']);
            if (empty($_SESSION['HTTP_REFERER']))
                header("Location: index.php");
            else
                header("Location: " . $_SESSION['HTTP_REFERER']);
        }
        else {
            $error_message = "Erreur de connexion !<br>Veuillez vérifier votre pseudo et votre mot de passe.";
            $error_image = "bad_pass.jpg";
        }
    }
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Erreur</title>
</head>
<body bgcolor="#2e3131" style="color: white;">
    <h1 align='center'><?= $error_message ?></h1>
    <p align='center'><img src='/img/<?= $error_image ?>' alt="error"></p>
</body>
</html>