{{%AUTOESCAPE context="HTML"}}
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="diffview.css">
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
			{{#DIFFERENCE_SET}}
			<div class="diffOutput" style="{{FILE_DISPLAY_PROPERTY:none}}"> <!-- repeat for each change in a file -->
				<div class="header">
					<div class="codeTitle" >{{LEFT_FILE}}</div>
					<div class="codeTitle" >{{RIGHT_FILE}}</div>
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
			<div class="dirDiff" style="{{DIR_DISPLAY_PROPERTY:none}}">
				<div class="dirTitle">
				{{DIR_DIFFERENCE}}
				</div>
			</div>
			{{/DIFFERENCE_SET}}
			<div>
		</main>

	</body>

</html>
