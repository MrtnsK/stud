<?php
function check_pair($login, $passwd) {
    if (!file_exists("private/users"))
        return False;
    $fake_db = unserialize(file_get_contents("private/users"));
    if (!isset($fake_db[$login]) || !password_verify($passwd, $fake_db[$login]['passwd']))
        return False;
    return True;
}