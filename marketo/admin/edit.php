<?php
session_start();
$fake_db = array();
if (file_exists("../private/users"))
    $fake_db = array_filter(unserialize(file_get_contents("../private/users")));
if ($fake_db[$_SESSION['login']]['rights'] !== -2) {
    header("HTTP/1.0 403 Forbidden");
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}
$articles_db = array();
if (file_exists("../private/articles"))
    $articles_db = array_filter(unserialize(file_get_contents("../private/articles")));
if (isset($_POST['article_id'], $articles_db[$_POST['article_id']]) && $_POST['submit'] === "OK") {
    // IMAGE OK
    if (!empty($_FILES["image"]["tmp_name"])) {
        // FILE UPLOAD
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
        unlink($articles_db[$_POST['article_id']]['image']);
        $articles_db[$_POST['article_id']]['image'] = $target_file;
    }
    // NAME
    if (isset($_POST['name']))
        $articles_db[$_POST['article_id']]['name'] = substr($_POST['name'], 0, 30);
    // PRICE
    if (isset($_POST['price']))
        $articles_db[$_POST['article_id']]['price'] = substr($_POST['price'], 0, 7);
    // DESCRIPTION
    if (isset($_POST['description']))
        $articles_db[$_POST['article_id']]['description'] = substr($_POST['description'], 0, 100);
    // CATEGORIE
    if (isset($_POST['categorie']))
        $articles_db[$_POST['article_id']]['categorie'] = $_POST['categorie'];
}
$f = fopen("../private/articles", "w");
flock($f, LOCK_EX);
file_put_contents("../private/articles", serialize($articles_db));
flock($f, LOCK_UN);
fclose($f);
header("Location: index.php");
?>