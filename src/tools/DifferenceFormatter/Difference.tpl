{{%AUTOESCAPE context="HTML"}}
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="diffview.css" media="screen"/>
		<script src="jquery-2.1.3.js"></script>
		<!-- include css and javascript references here -->
	</head>
	<body>
		<header>
			<h1>Difference Report</h1>
			<h1 id="heading">{{HEADING}}</h1>
			<section id="folders">
				<h2 id="leftFolder">Left Folder: {{LEFT_PATH}}</h2>
  				<h2 id="rightFolder">Right Folder: {{RIGHT_PATH}}</h2>
 			</section>
			<h3 id="subHeading">{{DATE_GENERATED}}</h3>
		</header>
 		<main>
			<h4>Folder Differences</h4>
			{{#DIRECTORY_DIFFERNCE}}
			<div class="dirDiff" style="{{DIR_DISPLAY_PROPERTY:none}}">
				<div class="dirTitle">
				{{DIR_DIFFERENCE}}
				</div>
			</div>
			{{/DIRECTORY_DIFFERNCE}}

			<h4>File Differences</h4>
			{{#FILE_DIFFERNCE}}
			<div class="diffOutput"> <!-- repeat for each change in a file -->
				<div class="fileHeader">
					<a href="file:///{{LEFT_FILE}}"><div class="fileTitle" >{{LEFT_FILE}}</div></a>
					<a href="file:///{{LEFT_FILE}}"><div class="fileTitle" >{{RIGHT_FILE}}</div></a>
				</div>
				{{#DIFFERENCE_SET}}
				<div id="changeHeaderParent">
					<div class="changeHeader" id="changeHeader">
						<div class="codeTitle" >Lines {{LEFT_STARTLINE}} through {{LEFT_ENDLINE}}.</div>
						<div class="codeTitle" >Lines {{RIGHT_STARTLINE}} through {{RIGHT_ENDLINE}}.</div>
					</div>
					<div class="codeList"><!-- repeate for each line of code -->
						{{#LINES}}
						<div class="codeSide">
							<div class="lineNumber">
								{{LEFT_LINE_NUMBER}}
							</div>
							<div class="{{LEFT_LINE_CLASS}}">
								<pre>{{LEFT_LINE}}</pre>
							</div>
						</div>
						<div class="codeSide">
							<div class="lineNumber">
								{{RIGHT_LINE_NUMBER}}
							</div>
							<div class="{{RIGHT_LINE_CLASS}}">
								<pre>{{RIGHT_LINE}}</pre>
							</div>
						</div>
						{{/LINES}}
					</div>
				</div>
				{{/DIFFERENCE_SET}}
			</div>
			{{/FILE_DIFFERNCE}}
		</main>

	</body>
	<script>
	$(document).ready(function()
	{
		$('div.changeHeader').click(function(evt)
		{
			$(evt.target).closest('div#changeHeaderParent').children('div.codeList').toggle('fast');
		});
	});
	</script>
</html>
