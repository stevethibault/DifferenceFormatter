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
			<h1 id="heading">Difference Report for {{INSTRUMENT}}</h1>
			<section id="folders">
				<h2 id="leftFolder">Left Folder: {{LEFT_PATH}}</h2>
				<h2 id="rigthFolder">Right Folder: {{RIGHT_PATH}}</h2>
			</section>
			<h3 id="subHeading">{{DATE_GENERATED}}</h3>
		</header>
		<main>
			<ul style="list-style-type: none">
				{{#FILE_DIFFERENCES}}
				<li style="{{FILE_DISPLAY_PROPERTY:none}}">
					{{#DIFFERENCE_SET}}
					<div id="diffoutput" style="width:100%">
						<table class="diff">
							<thead>
								<tr>
									<th class="texttitle" colspan="2">{{LEFT_FILE}}</th>
									<th class="texttitle" colspan="2">{{RIGHT_FILE}}</th>
								</tr>
							</thead>
							<tbody>
								{{#LINES}}
								<tr>
									<td class="lineNumbers">{{LEFT_LINE_NUMBER}}</td>
									<td class="{{LEFT_LINE_CLASS}}"><pre>{{LEFT_LINE}}</pre></td>
									<td class="lineNumbers">{{RIGHT_LINE_NUMBER}}</td>
									<td class="{{RIGHT_LINE_CLASS}}"><pre>{{RIGHT_LINE}}</pre></td>
								</tr>
								{{/LINES}}
							</tbody>
						</table>
					</div>
					{{/DIFFERENCE_SET}}
				</li>
				<li style="{{DIRECTORY_DISPLAY_PROPERTY:none}}"> {{DIRECTORY_DIFFERENCE}} </li>
				{{/FILE_DIFFERENCES}}
			</ul>
		</main>
	</body>
</html>


