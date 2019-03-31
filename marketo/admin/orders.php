<?php
session_start();

$fake_db = array();
if (file_exists("../private/users"))
    $fake_db = array_filter(unserialize(file_get_contents("../private/users")));
if ($fake_db[$_SESSION['login']]['rights'] !== -2) {
    header("HTTP/1.0 403 Forbidden");
    echo "<title>El Marketo</title>";
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}

$orders = array();
if (file_exists("../private/orders"))
    $orders = array_filter(unserialize(file_get_contents("../private/orders")));

$articles_db = array();
if (file_exists("../private/articles"))
    $articles_db = array_filter(unserialize(file_get_contents("../private/articles")));

?>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <title>Admin</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="../css/admin.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="../css/orders.css" />
    <link rel="shortcut icon" href="../img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="../img/favicon.ico" type="image/x-icon">
    <script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0/dist/Chart.min.js" integrity="sha256-Uv9BNBucvCPipKQ2NS9wYpJmi8DTOEfTA/nH2aoJALw=" crossorigin="anonymous"></script>
</head>

<body bgcolor="#2e3131" style="margin: 0;">
    <div class="head">
        <a href="/index.php">
            <h1 class="headtitle">El Marketo</h1>
        </a>
        <div class="cont">
            <a href="/admin">
                <button class="cart">Home admin</button>
            </a>
            <a href="/admin/cat.php">
                <button class="cart">Catégorie menu</button>
            </a>
            <a href="/admin/user.php">
                <button class="cart">Users menu</button>
            </a>
            <a href="/logout.php">
                <button class="logout">Se déconnecter</button>
            </a>
        </div>
    </div>
    <h2 class="texte">Historique des commandes</h2>
    <canvas id="myChart" width="900" height="400"></canvas>
<script>
<?php
    function random_color_part() {
        $col = mt_rand(11,255);
        return str_pad(dechex($col), 2, '0', STR_PAD_LEFT).";".str_pad(dechex($col - 10), 2, '0', STR_PAD_LEFT);
    }
    $colors = array();
    $colors2 = array();
    $names = array_column($articles_db, 'description');
    foreach ($names as &$name) {
        $name = "'" . $name . "'";
        $col1 = explode(";", random_color_part());
        $col2 = explode(";", random_color_part());
        $col3 = explode(";", random_color_part());
        array_push($colors, "'#". $col1[0] . $col2[0] . $col3[0] ."'");
        array_push($colors2, "'#". $col1[1] . $col2[1] . $col3[1] ."'");
    }
    $qte = array_fill(0, count($names), 0);
    foreach ($names as $index => $art_desc) {
        foreach ($orders as $order) {
            foreach ($order['order'] as $ord) {
                if ("'".$ord['description']."'" === $art_desc) {
                    $qte[$index] += $ord['qte'];
                }
            }
        }
    }
?>
var ctx = document.getElementById('myChart').getContext('2d');
var myChart = new Chart(ctx, {
    type: 'bar',
    data: {
        labels: [<?= join(', ', $names) ?>],
        datasets: [{
            label: 'Total des ventes',
            data: [<?= join(', ', $qte) ?>],
            backgroundColor: [<?= join(', ', $colors) ?>],
            borderColor: [<?= join(', ', $colors2) ?>],
            borderWidth: 4
        }]
    },
    options: {
        scales: {
            yAxes: [{
                ticks: {
                    beginAtZero: true
                }
            }]
        }
    }
});
</script>
    <?php if (count($orders)) { ?>
        <div class="admin-tab-center">
            <table id="orders-table">
                <tbody>
                    <tr>
                        <th style="text-align:center;">Utilisateur</th>
                        <th style="text-align:center;" width="5%">Nombre d'articles</th>
                        <th style="text-align:center;" width="10%">Total ( en € )</th>
                    </tr>
                    <?php foreach ($orders as $order) { ?>
                        <tr>
                            <td align='center'>
                                <?= htmlspecialchars($order['login']) ?>
                            </td>
                            <td align='center'>
                                <?= number_format(array_sum(array_column($order['order'], 'qte'))) ?>
                            </td>
                            <td align='center'>
                                <?= number_format(array_sum(array_column($order['order'], 'price')) * array_sum(array_column($order['order'], 'qte')) ,2) ?>
                            </td>
                        </tr>
                    <?php } ?>
                </tbody>
            </table>
        </div>
    <?php } ?>
    <footer> © Copyright 2019 All rights reserved to agissing and kemartin.</footer>
</body>

</html>