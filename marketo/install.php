<?php
if (isset($_SERVER['REQUEST_METHOD'])) {
    header("HTTP/1.0 403 Forbidden");
    echo "<title>El Marketo</title>";
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}
$urls = array("https://i.ibb.co/D1YghNV/Adidas-etq.png", "https://i.ibb.co/cFdqSKY/adidas-sb.png", "https://i.ibb.co/B4RGrtc/adidas-swif.png", "https://i.ibb.co/7RftGxG/Adidas-Yeezy-Boost-350-V2.png", "https://i.ibb.co/W05Pj0z/asics-couleur.png", "https://i.ibb.co/844VvPb/converse-chuck-taylor-all-star-basse.png", "https://i.ibb.co/8XmxMWq/Nike-Spiridon-Parra.png", "https://i.ibb.co/nDcQrQD/Nike-Air-Presto-Off-White.png", "https://i.ibb.co/myvqdnx/vans-blanche.png");
if (!file_exists("./img/article"))
    mkdir("./img/article");
foreach ($urls as $url) {
    $split = end(explode("/", $url));
    copy($url, "./img/article/".$split);
}
if (!file_exists("./private"))
    mkdir("./private");
copy("https://pastebin.com/raw/0xHjETuP", "./private/articles");
copy("https://pastebin.com/raw/MkQJyYLC", "./private/users");
copy("https://pastebin.com/raw/aRwFvEz5", "./private/categorie");
?>