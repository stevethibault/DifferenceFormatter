{{%AUTOESCAPE context="HTML"}}
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<!-- include css and javascript references here -->
	</head>
	<body>
		<header>
			<h1 id="heading">Difference Report for {{INSTRUMENT}}</h1>
			<section id="folders">
				<h2 id="leftFolder">Left Folder: {{LEFT_PATH}}</h2>
				<h2 id="rigthFolder">Right Folder: {{RIGHT_PATH}}</h2>
			</section>
			<h3 id="subHeading">{{DATE_GENERATED}}</h3>
		</header>
		<main>
			<ul>
			{{#DIFFERENCES}}
			<li style="{{FILE_DISPLAY_PROPERTY}}"> {{FILE_DIFFERENCE}} 
				<div id="fileChangesHeader">
					<label>{{LEFT_RELATIVE_PATH}}</label>
					<label>{{RIGHT_RELATIVE_PATH}}</label>
				</div>
				{{#CHUNKS}}
					{{#LINES}}
					{{/LINES}}
				{{/CHUNKS}}
			</li>
			<li style="{{DIRECTORY_DISPLAY_PROPERTY}}"> {{DIRECTORY_DIFFERENCE}} </li>
			{{/DIFFERENCES}}
			</ul>
		</main>
	</body>
</html>