<?php
function check_log() {
    session_start();
    if (!file_exists("private/users") || !isset($_SESSION['login']))
        return False;
    $fake_db = unserialize(file_get_contents("private/users"));
    if (!isset($fake_db[$_SESSION['login']]))
        return False;
    return True;
}