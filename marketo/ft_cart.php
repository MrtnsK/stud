<?php
//fonctions de gestion panier
    include("ft_encrypt.php");
    function get_cart($users_db) {
        if (!empty($_SESSION['login']) && !empty($users_db[$_SESSION['login']])) {
            if ($cart = unserialize($users_db[$_SESSION['login']]['cart']))
                return $cart;
            return array();
        }
        elseif (isset($_COOKIE['cart']) && ($cart = unserialize(decrypt_data($_COOKIE['cart']))))
            return $cart;
        else
            return array();
    }
    function save_cart($data, $users_db) {
        if (isset($_SESSION['login'], $users_db[$_SESSION['login']])) {
            $users_db[$_SESSION['login']]['cart'] = serialize($data);
            file_put_contents("private/users", serialize(array_filter($users_db)), LOCK_EX);
        }
        else
            setcookie('cart', encrypt_data(serialize($data)));
    }
    function cart_merge($cart, $cart2) {
        foreach ($cart2 as $index => $article) {
            if (!isset($cart[$index])) {
                $new_article = $article;
                $new_article['qte'] = $article['qte'];
                $cart[$index] = $new_article;
            } else
                $cart[$index]['qte'] += $article['qte'];
        }
        return $cart;
    }
?>