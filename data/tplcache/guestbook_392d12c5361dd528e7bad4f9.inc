<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?>﻿<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $cfg_webname; ?> - 留言本</title>
<link href="<?php echo $cfg_templeturl; ?>/default/style/dedecms.css" rel="stylesheet" type="text/css" media="screen" />
<link href="<?php echo $GLOBALS['cfg_templets_skin']; ?>/style/common.css" rel="stylesheet" type="text/css" />
<link href="<?php echo $GLOBALS['cfg_templets_skin']; ?>/style/style.css" rel="stylesheet" type="text/css" />
<link href="<?php echo $GLOBALS['cfg_templets_skin']; ?>/style/csss.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/js/jquery.min.js"></script>
<script type="text/javascript" src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/js/Functions.js"></script>
<script type="text/javascript" src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/js/FocusSlide.js"></script>
<script type="text/javascript" src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/js/ScrollPic.js"></script>
<script type="text/javascript" src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/js/iepngfix_tilebg.js"></script>
<script type="text/javascript" src="<?php echo $GLOBALS['cfg_templets_skin']; ?>/js/jquery-1.js"></script>
<style>
	.lefttd {
		border-left:1px solid #dedede;
		border-right:1px solid #dedede;
	}
	.ltd {
		border-left:1px solid #dedede;
		border-right:1px solid #dedede;
		border-top:1px solid #dedede;
		border-bottom:1px dashed #dedede;
	}
	.msgtd {
		line-height:180%;
		border-right:1px solid #dedede;
		padding:5px;
		height:80px;
	}
	.timetd {
		border-right:1px solid #dedede;
		border-top:1px solid #dedede;
		border-bottom:1px dashed #dedede;
		padding-left:5px;
	}
	.bottomtd {
		border-right:1px solid #dedede;
		border-top:1px dashed #dedede;
		padding-left:5px;
	}
	.writetable td {
		padding: 5px;
	}
	.writetd {
		background:url(img/wbg.gif);
	}
	.pagetable {
		border:1px solid #dedede;
		margin-bottom:8px;
		background:#FBFEED;
	}
 .pagelistbox {
 	
 }
 .pagelistbox span{
 	  border:1px solid #dedede;
 	  padding:2px;
 	  margin-right:3px;
 	  background:#E8F9BF;
 }
 .pagelistbox a {
 	  border:1px solid #dedede;
 	  padding:2px;
 	  margin-right:3px;
 	  background:#E8F9BF;
 	  padding-left:5px;
 	  padding-right:5px;
 }
 .rebox {
   width:98%;
   padding:3px;
   border:1px solid #dedede;
 }
</style>
</head>
<body id="wrapper">
<div id="head">
<?php session_start(); 
   pasterTempletDiy("default/head.html");
?>
</div>
<!-- /header -->
<div class="w960 clear center mt1">
  <div class="sp-title">
    <h2>留言本</h2>
    <span class="more">
    	 <a href="#write">[发布留言]</a> &nbsp; 
    	 <a href="<?php echo $cfg_basehost;?>/">[返回主页]</a>
    </span> 
  </div>
 <?php 

  $ntt=0;

  $bgcc = '#FBFEED';

  if ($_SESSION['dede_admin_id']=='1'){

  
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
    <table width='100%' border='0' align="center" cellpadding='0' cellspacing='0' style="<?php echo (($ntt==0) ? "background:{$bgcc}" : 'background:#ffffff'); ?>">
      <tr>
        <td width='160' align="center" class='ltd'>
        	<b>姓名：<?php echo $fields['uname']; ?></b>
        </td>
      	<td height="26" class='timetd'>
      		<img height='16' src='guestbook/images/time.gif' width='16' /> 发布时间: <?php echo MyDate('m-d H:i',$fields['dtime']); ?>
      	  &nbsp; 
      	  主题：<?php echo $fields['title']; ?>
      	</td>
      </tr>
      <tr>
      	<td width='160' rowspan='2' align="center" class='lefttd'>
        	<table width='160' border='0' align="center" cellpadding='1' cellspacing='2'>
          	<tr>
            	<td height="80" align="center">
            		<img src='guestbook/images/01.gif' border=0 /> <?php echo GetIsCheck($fields['ischeck'],$fields['id'])?>
            	</td>
          	</tr>
          	<tr>
            	<td height="20">&nbsp;来自IP：<?php echo preg_replace("#[^\.]*\.[^\.]*$#","*.*",$fields['ip']); ?></td>
          	</tr>
          	<tr>
            	<td height="20">&nbsp;电话：<?php echo $fields['qq']?></td>
          	</tr>
        	</table>
        </td>
      	<td class='msgtd'><?php echo $fields['msg']; ?></td>
      </tr>
      <tr>
      	<td height="26" class="bottomtd">
      		<a><img src='guestbook/images/mail.gif' border=0 width='16' height='16' />邮箱：<?php echo $fields["email"]?></a> &nbsp;
			<a><img src='guestbook/images/home.gif' border=0 width='16' height='16' />地址：<?php echo $fields['homepage']?></a> &nbsp;

      		<a href='guestbook.php?action=admin&id=<?php echo $fields['id']; ?>'><img src='guestbook/images/quote.gif' border=0 height=16 width=16 />[回复/编辑]</a> &nbsp;
      		<?php if($g_isadmin) { ?>
      		<a href='guestbook.php?action=admin&id=<?php echo $fields['id']; ?>&job=del'><img src='guestbook/images/del.gif' border=0 height=16 width=16 />[删除]</a>
      	  <?php }  ?>
      	</td>
      </tr>
    </table>
    <?php if($ntt==0){$ntt=1;}else{ $ntt=0; } 
}
} } ?>
   <table border='0' cellpadding='0' cellspacing='0' width='100%' align='center' class='pagetable'>
     <tr>
        <td align="center" height='28'> <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
 </td>
     </tr>
   </table>
    
   
   <div id="Table">
            <div class="fd_tit">如果您对我们有什么想法或意见，请填写以下表格，我们会尽快与您联系!（<span class="fd_b">备注：带*号的必填</span>）</div>
			<form method="post" action="/plus/guestbook.php" name="form1">
        <input type='hidden' name='action' value='save' />
            <ul>
            	<li class="fd_l">姓名</li>
                <li class="fd_r">
                  <input name="uname" id="txtName" class="fd_ip1" type="text"> <span class="fd_b">*</span>
                </li>
                <div class="clear"></div>
            	<li class="fd_l">联系电话</li>
                <li class="fd_r">
                  <input name="qq" id="txtPhone" class="fd_ip1" type="text"> <span class="fd_b">*</span>
                </li>
                <div class="clear"></div>
            	<li class="fd_l">E-mail</li>
                <li class="fd_r">
                  <input name="email" id="txtEmail" class="fd_ip1" type="text">&nbsp;
                    <span class="fd_b">*</span></li>
                <div class="clear"></div>
            	<li class="fd_l">联系地址</li>
                <li class="fd_r">
                  <input name="homepage" id="txtAddress" class="fd_ip2" type="text"><span class="fd_b">*</span>
                </li>
                <div class="clear"></div>
            	<li class="fd_l">主题</li>
                <li class="fd_r">
                  <input name="title" id="txtTitle" class="fd_ip2" type="text"><span class="fd_b">*</span>
                </li>
                <div class="clear"></div>
            	<li class="fd_l">内容</li>
                <li class="fd_r">
                  <textarea name="msg" id="txtContact" class="fd_con"></textarea> <span class="fd_b">*</span>
                </li>
                <div class="clear"></div>
                <li class="fd_l">验证码</li>
                <li class="fd_r">
                
                  <input name="validate" id="vdcode2"  class="fd_ip1" type="text"> <img id="ValidateCodeImage1" onclick="this.src='?width=0&amp;height=0&amp;ValidateCodeImage1='+Math.random()" src="../include/vdimgck.php" alt="点击刷新换一个验证码" style="cursor:pointer;" align="middle"> <span class="fd_b">*</span>
                </li>
                    <span id="RequiredFieldValidator5" style="color:Red;display:none;"></span>
                <div class="clear"></div>
                <li class="fd_l"></li>
                <li class="fd_r">
                  <input onclick="if (typeof(Page_ClientValidate) == 'function') Page_ClientValidate(''); " name="btsub" id="btsub" class="fd_sub" value="提 交" type="submit">
                  <input name="button" class="fd_rec" id="btrec" value="取 消" type="reset">
                    <div id="ValidationSummary1" style="color:Red;display:none;">

</div>
                </li>
            </ul>
			</form>
            </div>
   
   <br />
</div>

<?php
   pasterTempletDiy("default/foot.html");
?>

</div>
</body>
</html>