<?php
    define('AES_256_CBC', 'aes-256-cbc');
    // fonctions d'encryption
    function encrypt_data($clear_data) {
        $key_ = base64_decode("2ogigrp8fg6NhcJ8lOro92Ji+1Kx56ytcerinPce1K8=");
        $iv = openssl_random_pseudo_bytes(openssl_cipher_iv_length(AES_256_CBC));
        $encrypted = openssl_encrypt($clear_data, AES_256_CBC, $key_, 0, $iv);
        return ($encrypted . ':' . base64_encode($iv));
    }
    function decrypt_data($encrypted_data) {
        $key_ = base64_decode("2ogigrp8fg6NhcJ8lOro92Ji+1Kx56ytcerinPce1K8=");
        $parts = explode(':', $encrypted_data);
        $decrypted = openssl_decrypt($parts[0], AES_256_CBC, $key_, 0, base64_decode($parts[1]));
        return ($decrypted);
    }
?>