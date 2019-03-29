<?php
    include("ft_cart.php");
    function log_user($user) {
        session_start();
        // récupération de la db users
        $users_db = array();
        if (file_exists("private/users"))
            $users_db = unserialize(file_get_contents("private/users"));

        if (isset($_COOKIE['cart']) && $cart = unserialize(decrypt_data($_COOKIE['cart']))) {
            $cart_sav = 1;
        }
        if (isset($_SESSION['login']) && $_SESSION['login'] === $user)
            return True;
        save_cart(array(), $users_db);
        $_SESSION['login'] = $user;
        save_cart(cart_merge(get_cart($users_db), $cart), $users_db);
        return True;
    }
?>