<!DOCTYPE html><html lang="en">
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="diffview.css">
		<!-- include css and javascript references here -->
	</head>
	<body>
		<header>
			<h1 id="heading">Difference Report for Velox Core TUV to Altus UV Core</h1>
			<section id="folders">
				<h2 id="leftFolder">Left Folder: C:\Q\ICS\OEMInstruments\TUV\CoreTUV</h2>
  			<h2 id="rightFolder">Right Folder: C:\Q\ICS\VeloxInstruments\TUV\CoreTUV</h2>
 			</section>
			<h3 id="subHeading">Fri Mar 20 16:11:54 2015 </h3>
		</header>
 		<main>
			{{#DIFFERENCE_SET}}
			<div class="diffOutput" style="{{FILE_DISPLAY_PROPERTY:none}}"> <!-- repeat for each change in a file -->
				<div class="header">
					<div class="textTitle" >{{LEFT_FILE}}</div>
					<div class="textTitle" >{{RIGHT_FILE}}</div>
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
			{{/DIFFERENCE_SET}}			<div>		</main>
	</body>
</html>