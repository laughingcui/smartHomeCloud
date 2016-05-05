<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:v="urn:schemas-microsoft-com:vml">
<head>
<title>更换头像</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" type="text/css" href="/static/platform/upload/css/main.css" />
<link rel="Stylesheet" type="text/css" href="/static/platform/upload/css/jquery-ui-1.7.2.custom.css"  /> 
<style type="text/css">
*{margin:0px;font-size:12px}
.crop{width:680px; margin:20px auto; border:1px solid #d3d3d3; padding:4px; background:#fff}
#cropzoom_container{float:left; width:500px}
#preview{float:left; width:150px; height:200px; border:1px solid #999; margin-left:10px; padding:4px; background:#f7f7f7;}
.page_btn{float:right; width:150px;  margin-top:20px; line-height:30px; text-align:center}
.clear{clear:both}
.btn{cursor:pointer}


.back{background:#d8d8d8;height:70px;margin:auto 0;}
.ulcls{list-style:none;padding-left:20px;line-height:70px;}
.logowidth{width:220px;}
.pl10{padding-left:10px;}
.menupos{top: 0px; position: absolute; left: 260px; overflow: hidden;height:70px;width:700px;line-height:70px;}
.firstli{background:#65765f;width:80px;padding:5px;height:70px;float:left;text-align:center;line-height:70px;}
.sencli{background:#39bd05;width:100px;text-align:center;float:left;height:70px;line-height:70px;border-left:1px solid #d8d8d8;}
.threeli{background:#65765f;width:80px;padding:5px;height:70px;float:left;text-align:center;line-height:70px;border-left:1px solid #d8d8d8;}
.lia{color:#ffffff;font-weight:bold;text-decoration:none;}

.textpos{text-align:left;top: 2px; position: absolute; right: 50px; overflow: hidden;font-size:12px;color:#363d34;line-height:16px;}
.texta{color:#0652ec;text-decoration:none;}
</style>


<script type="text/javascript" src="/static/platform/upload/js/jquery.js"></script>
<script type="text/javascript" src="/static/platform/upload/js/jquery-ui-1.8.custom.min.js"></script>
<script type="text/javascript" src="/static/platform/upload/js/jquery.cropzoom.js"></script>
<script type="text/javascript">
$(function() {
     var cropzoom = $('#cropzoom_container').cropzoom({
          width: 500,
          height: 360,
          bgColor: '#ccc',
          enableRotation: true,
          enableZoom: true,
          selector: {
			   w:150,
			   h:200,
			   showPositionsOnDrag:true,
			   showDimetionsOnDrag:false,
               centered: true,
			   bgInfoLayer:'#fff',
               borderColor: 'blue',
			   animated: false,
			   maxWidth:150,
			   maxHeight:200,
               borderColorHover: 'yellow'
           },
           image: {
               //source: 'http://www.js-css.cn/jscode/focus/focus19/images/b2.jpg',
               source: '/static/platform/upload/b2.jpg',
               width: 450,
               height: 300,
               minZoom: 30,
               maxZoom: 150
            }
      });
	  $('#crop').click(function(){
		   cropzoom.send('/static/platform/upload/resize_and_crop.php', 'POST', {}, function(imgRet) {
		   alert(imgRet);
		  console.log(imgRet);
               / $('#generated').attr('src', imgRet);
           });			   
	  });
	  $('#restore').click(function(){
		   $('#generated').attr('src', '/static/platform/upload/tmp/head.gif');
		   cropzoom.restore();					  
	  });
});

 
 
                //图片上传预览    IE是用了滤镜。
        function previewImage(file)
        {
          var MAXWIDTH  = 150; 
          var MAXHEIGHT = 200;
          var div = document.getElementById('preview');
          if (file.files && file.files[0])
          {
              //div.innerHTML ='<img id=generated>';
              var img = document.getElementById('generated');
              img.onload = function(){
                var rect = clacImgZoomParam(MAXWIDTH, MAXHEIGHT, img.offsetWidth, img.offsetHeight);
                img.width  =  rect.width;
                img.height =  rect.height;
//                 img.style.marginLeft = rect.left+'px';
                img.style.marginTop = rect.top+'px';
              }
              var reader = new FileReader();
              reader.onload = function(evt){img.src = evt.target.result;}
              reader.readAsDataURL(file.files[0]);
          }
          else //兼容IE
          {
            var sFilter='filter:progid:DXImageTransform.Microsoft.AlphaImageLoader(sizingMethod=scale,src="';
            file.select();
            var src = document.selection.createRange().text;
            //div.innerHTML = '<img id=generated>';
            var img = document.getElementById('generated');
            img.filters.item('DXImageTransform.Microsoft.AlphaImageLoader').src = src;
            var rect = clacImgZoomParam(MAXWIDTH, MAXHEIGHT, img.offsetWidth, img.offsetHeight);
            status =('rect:'+rect.top+','+rect.left+','+rect.width+','+rect.height);
            //div.innerHTML = "<div id=divhead style='width:"+rect.width+"px;height:"+rect.height+"px;margin-top:"+rect.top+"px;"+sFilter+src+"\"'></div>";
			img.attr('src',src);
          }
        }
        function clacImgZoomParam( maxWidth, maxHeight, width, height ){
            var param = {top:0, left:0, width:width, height:height};
            if( width>maxWidth || height>maxHeight )
            {
                rateWidth = width / maxWidth;
                rateHeight = height / maxHeight;
                 
                if( rateWidth > rateHeight )
                {
                    param.width =  maxWidth;
                    param.height = Math.round(height / rateWidth);
                }else
                {
                    param.width = Math.round(width / rateHeight);
                    param.height = maxHeight;
                }
            }
             
            param.left = Math.round((maxWidth - param.width) / 2);
            param.top = Math.round((maxHeight - param.height) / 2);
            return param;
        }
</script>

</head>

<body>
<!--JS代码网头部-->
<div id="main">
 
<div class="crop">
   <div id="cropzoom_container"></div>
   <div id="preview"><img id="generated" src="/static/platform/upload/tmp/head.gif"  /></div>
   <div class="page_btn">
      <input type="button" class="btn" id="crop" value="剪切照片" />
      <input type="button" class="btn" id="restore" value="照片复位" />
   </div>
   <div class="clear">
	  <input type="file" onchange="previewImage(this)" />  </div>
</div>
</div>

</body>
</html>
