<?php
    session_start();
    include("check_log.php");
    include("ft_cart.php");

    // récupération de la db articles
    $articles_db = array();
    if (file_exists("private/articles"))
        $articles_db = unserialize(file_get_contents("private/articles"));

    // récupération de la db users
    $users_db = array();
    if (file_exists("private/users"))
        $users_db = unserialize(file_get_contents("private/users"));

    // ajout d'article au panier
    if (isset($_POST['article_id'], $articles_db[$_POST['article_id']]) && $_POST['submit'] === 'OK') {
        $cart = get_cart($users_db);
        if (!isset($cart[$_POST['article_id']])) {
            $article = $articles_db[$_POST['article_id']];
            $article['qte'] = 1;
            $cart[$_POST['article_id']] = $article;
        } else
            $cart[$_POST['article_id']]['qte']++;
        save_cart($cart, $users_db);
        header("Location: cart.php");
    }

    // methode get (gestion article du panier)
    elseif (isset($_GET['action'])) {
        $cart = get_cart($users_db);
        switch ($_GET['action']) {
            case "add":
                if (isset($_GET['index'], $articles_db[$_GET['index']]))
                    $cart[$_GET['index']]['qte']++;
                break;
            case "min":
                if (isset($_GET['index'], $articles_db[$_GET['index']])) {
                    $cart[$_GET['index']]['qte']--;
                    if ($cart[$_GET['index']]['qte'] <= 0)
                        unset($cart[$_GET['index']]);
                }
                break;
            case "del":
                if (isset($_GET['index'], $articles_db[$_GET['index']]))
                    unset($cart[$_GET['index']]);
                break;
            case "empty":
                unset($cart);
                break;
            case "buy":
                if (!check_log()) {
                    $_SESSION['HTTP_REFERER'] = $_SERVER['REQUEST_URI'];
                    header("Location: login.html");
                    exit();
                } else {
                    if (!file_exists("private"))
                        mkdir("private");
                    $orders_db = array();
                    if (file_exists("private/orders"))
                        $orders_db = unserialize(file_get_contents("private/orders"));
                    $new_order['login'] = $_SESSION['login'];
                    $new_order['order'] = $cart;
                    array_push($orders_db, $new_order);
                    $f = fopen("private/orders", "w");
                    flock($f, LOCK_EX);
                    file_put_contents("private/orders", serialize($orders_db));
                    flock($f, LOCK_UN);
                    fclose($f);
                    $cart = array();
                }
                break;
        }
        save_cart($cart, $users_db);
        header("Location: cart.php");
    }
    $cart = get_cart($users_db);
?>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <title>Panier</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/header.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/cart.css" />
    <link rel="shortcut icon" href="/img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="/img/favicon.ico" type="image/x-icon">
</head>

<body bgcolor="#2e3131" style="margin: 0;">
    <div class="head">
        <a href="/index.php">
            <h1 class="headtitle">El Marketo</h1>
            </a>
            <div class="cont">
            <a href="/index.php">
                    <button class="logout">Accueil</button>
                </a>
            <?php if (check_log()) { ?>
                <a href="/logout.php">
                    <button class="logout">Se déconnecter</button>
                </a>
                <?php } else { ?>
            <a href="/login.html">
                <button class="logout">Se connecter</button>
            </a>
        <?php } ?>
            </div>
    </div>
    <div id="shopping-cart">
        <?php if (isset($_COOKIE['cart']) && count($cart)) {?>
        <h1>Panier</h1>
        <a id="btnEmpty" href="cart.php?action=empty">Vider le panier</a>
        <table class="tbl-cart" cellpadding="10" cellspacing="1">
            <tbody>
                <tr>
                    <th style="text-align:left;">Nom</th>
                    <th style="text-align:left;">Description</th>
                    <th style="text-align:right;" width="5%">Pointure</th>
                    <th style="text-align:right;" width="5%">Qte.</th>
                    <th style="text-align:right;" width="10%">Prix<br>( in €)</th>
                    <th style="text-align:right;" width="10%">Total<br>( in €)</th>
                    <th style="text-align:center;" colspan="2" width="5%">Modifier</th>
                    <th style="text-align:center;" width="5%">Supprimer</th>
                </tr>
                <?php
                $total_price = 0;
                foreach ($cart as $index => $value) {
                    $total_price += $value['price'] * $value['qte'];
                    $total_qte += $value['qte'];
                ?>
                <tr>
                    <td><img src="<?= $value['image'] ?>"
                            class="cart-item-image"><?= htmlspecialchars($value['name']) ?></td>
                    <td><?= htmlspecialchars($value['description']) ?></td>
                    <td style="text-align:center;">
                        <div id="pointure">
                        <select id="hidsel">
                            <?php $i = 35;
                            while ($i <= 45 &&  $i++) { ?>
                                <option><?= $i?></option>
                                <?php }?>
                        </select></div></td>
                    <td style="text-align:center;"><?= $value['qte'] ?></td>
                    <td style="text-align:right;"><?= number_format($value['price'], 2) ?></td>
                    <td style="text-align:right;"><?= number_format($value['price']*$value['qte'], 2) ?></td>
                    <td style="text-align:center;">
                        <a href="cart.php?action=add&index=<?= $index ?>" class="btnAction">➕</a>
                    </td>
                    <td style="text-align:center;">
                        <a href="cart.php?action=min&index=<?= $index ?>" class="btnAction">➖</a>
                    </td>
                    <td style="text-align:center;">
                        <a href="cart.php?action=del&index=<?= $index ?>" class="btnAction">❌</a>
                    </td>
                </tr>
                <?php } ?>
                <tr>
                    <td colspan="3" align="right">Total:</td>
                    <td align="center"><?= $total_qte ?></td>
                    <td align="right" colspan="2"><strong><?= number_format($total_price, 2) ?></strong></td>
                    <td colspan="3"></td>
                </tr>
            </tbody>
        </table>
            <a id="btnValidate" href="cart.php?action=buy">Payer</a>
        <?php } else { ?>
        <h1 align="center" style="margin-top: 15%">Votre panier est vide !</h1>
        <?php } ?>
    </div>
</body>
<footer> © Copyright 2019 All rights reserved to agissing and kemartin.</footer>
</html>