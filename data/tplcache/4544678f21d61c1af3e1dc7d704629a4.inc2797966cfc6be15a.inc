<?php
$z[0]=Array("field","",13,41);
$z[0][4]['name']="typeurl";
$z[1]=Array("field","",43,72);
$z[1][4]['name']="typename";
$z[2]=Array("sql","\r\n                      <li><a href='[field:typedir function='str_replace(\"{cmspath}\",\"\",@me)'/]' target='_blank'>[field:typename/]</a></li>\r\n                ",109,359);
$z[2][4]['sql']="Select * from dede_arctype where reid=~id~ ORDER BY id limit 0,7";

?>