<?php
session_start();
include("check_log.php");
$articles_db = array();
if (file_exists("private/articles"))
    $articles_db = array_filter(unserialize(file_get_contents("private/articles")));
if (file_exists("private/categorie"))
    $cat_db = array_filter(unserialize(file_get_contents("private/categorie")));
if (!empty($_POST))
    header("Location: index.php");
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>El Marketo</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Quicksand:300" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/log.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="/css/button.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="/css/article.css"/>
    <link rel="shortcut icon" href="/img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="/img/favicon.ico" type="image/x-icon">
</head>
<body bgcolor="#2e3131" style="margin: 0;">
<div class="head">
    <a href="index.php"><h1 class="headtitle">El Marketo</h1></a>
    <div class="cont">
        <?php if (check_log()) { ?>
            <div class="dropdown">
                <button class="dropbtn">Catégories</button>
                <div class="dropdown-content">
                    <a href="/index.php?categorie=all">All</a>
                    <?php if (!empty($cat_db)) { foreach ($cat_db as $cat) { ?>
                        <a href="/index.php?categorie=<?=urlencode($cat)?>"><?= htmlspecialchars($cat) ?></a>
                  <?php  }} ?>
                </div>
            </div>
            <a href="/cart.php">
                <button class="cart">Panier</button>
            </a>
            <a href="/account_edit.php">
                <button class="cart">Compte</button>
            </a>
            <a href="/logout.php">
                <button class="logout">Se déconnecter</button>
            </a>
        <?php } else { ?>
            <a href="/cart.php">
                <button class="cart">Panier</button>
            </a>
            <a href="/login.html">
                <button class="logout">Se connecter</button>
            </a>
        <?php } ?>
    </div>
</div>
<div class="boutique">
    <?php
    if (isset($_GET['categorie']) && $_GET['categorie'] !== "all")
        $articles_db = array_filter($articles_db, function ($value) {
            return ($value['categorie'] == $_GET['categorie']);
        });
    foreach ($articles_db as $index => $article) {
        ?>
        <div class="card">
            <div class="article-card price-div">
                <h1><?= htmlspecialchars($article['price']) ?>€</h1>
                <form action="cart.php" method="post">
                    <input type="hidden" name="article_id" value="<?= $index ?>"/>
                    <p>
                        <button type="submit" value="OK" name="submit">Acheter</button>
                    </p>
                </form>
            </div>
            <div class="article-card">
                <div class="img-cont"><img src="<?= $article['image'] ?>" alt="image"></div>
                <p><?= htmlspecialchars($article['name']) ?></p>
                <p><?= htmlspecialchars($article['description']) ?></p>
            </div>
        </div>
    <?php } ?>
</div>
<footer> © Copyright 2019 All rights reserved to agissing and kemartin.</footer>
</body>
</html>