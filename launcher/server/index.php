<?php

include 'updates.php';

$id = substr(htmlspecialchars($_GET["id"]),0,2); // try to avoid injXion

$available = false;
$result = array();
$i = 1;

foreach($downloads as $key => $value) {
	if ($key >= $id) {
		$result[$key] = $value;
		$i++;
		$available = true;
	}
}

// send back the data as json
header('Content-Type: application/json');

if ($available & $id > 0) {
	echo json_encode($result);
} else {
	echo json_encode(array("Error" => "Client is up-to-date."));
}	