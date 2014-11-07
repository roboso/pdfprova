/* This is an automatically generated file. Do not edit. */

/* pdf_util_js */

"var MuPDF = {\n"
"	monthName: ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'],\n"
"	shortMonthName: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'],\n"
"	monthPattern: /Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec/,\n"
"	dayName: ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'],\n"
"	padZeros: function(num, places) {\n"
"		var s = String(num)\n"
"		while (s.length < places)\n"
"			s = '0' + s\n"
"		return s;\n"
"	},\n"
"	convertCase: function(str, cmd) {\n"
"		switch (cmd) {\n"
"			case '>': return str.toUpperCase();\n"
"			case '<': return str.toLowerCase();\n"
"			default: return str;\n"
"		}\n"
"	},\n"
"};\n"
"/* display must be kept in sync with an enum in pdf_form.c */\n"
"var display = {\n"
"	visible: 0,\n"
"	hidden: 1,\n"
"	noPrint: 2,\n"
"	noView: 3,\n"
"};\n"
"var border = {\n"
"	s: \"Solid\",\n"
"	d: \"Dashed\",\n"
"	b: \"Beveled\",\n"
"	i: \"Inset\",\n"
"	u: \"Underline\",\n"
"};\n"
"var color = {\n"
"	transparent: [ \"T\" ],\n"
"	black: [ \"G\", 0 ],\n"
"	white: [ \"G\", 1 ],\n"
"	red: [ \"RGB\", 1,0,0 ],\n"
"	green: [ \"RGB\", 0,1,0 ],\n"
"	blue: [ \"RGB\", 0,0,1 ],\n"
"	cyan: [ \"CMYK\", 1,0,0,0 ],\n"
"	magenta: [ \"CMYK\", 0,1,0,0 ],\n"
"	yellow: [ \"CMYK\", 0,0,1,0 ],\n"
"	dkGray: [ \"G\", 0.25 ],\n"
"	gray: [ \"G\", 0.5 ],\n"
"	ltGray: [ \"G\", 0.75 ],\n"
"};\n"
"var util = {};\n"
"util.printd = function(fmt, d)\n"
"{\n"
"	var regexp = /(m+|d+|y+|H+|h+|M+|s+|t+|[^mdyHhMst]+)/g;\n"
"	var res = '';\n"
"	var i;\n"
"	if (!d)\n"
"		return null;\n"
"	var tokens = fmt.match(regexp);\n"
"	var length = tokens ? tokens.length : 0;\n"
"	for (i = 0; i < length; i++)\n"
"	{\n"
"		switch(tokens[i])\n"
"		{\n"
"			case 'mmmm': res += MuPDF.monthName[d.getMonth()]; break;\n"
"			case 'mmm': res += MuPDF.monthName[d.getMonth()].substring(0,3); break;\n"
"			case 'mm': res += MuPDF.padZeros(d.getMonth()+1, 2); break;\n"
"			case 'm': res += d.getMonth()+1; break;\n"
"			case 'dddd': res += MuPDF.dayName[d.getDay()]; break;\n"
"			case 'ddd': res += MuPDF.dayName[d.getDay()].substring(0,3); break;\n"
"			case 'dd': res += MuPDF.padZeros(d.getDate(), 2); break;\n"
"			case 'd': res += d.getDate(); break;\n"
"			case 'yyyy': res += d.getFullYear(); break;\n"
"			case 'yy': res += d.getFullYear()%100; break;\n"
"			case 'HH': res += MuPDF.padZeros(d.getHours(), 2); break;\n"
"			case 'H': res += d.getHours(); break;\n"
"			case 'hh': res += MuPDF.padZeros((d.getHours()+11)%12+1, 2); break;\n"
"			case 'h': res += (d.getHours()+11)%12+1; break;\n"
"			case 'MM': res += MuPDF.padZeros(d.getMinutes(), 2); break;\n"
"			case 'M': res += d.getMinutes(); break;\n"
"			case 'ss': res += MuPDF.padZeros(d.getSeconds(), 2); break;\n"
"			case 's': res += d.getSeconds(); break;\n"
"			case 'tt': res += d.getHours() < 12 ? 'am' : 'pm'; break;\n"
"			case 't': res += d.getHours() < 12 ? 'a' : 'p'; break;\n"
"			default: res += tokens[i];\n"
"		}\n"
"	}\n"
"	return res;\n"
"}\n"
"util.printx = function(fmt, val)\n"
"{\n"
"	var cs = '=';\n"
"	var res = '';\n"
"	var i = 0;\n"
"	var m;\n"
"	var length = fmt ? fmt.length : 0;\n"
"	while (i < length)\n"
"	{\n"
"		switch (fmt.charAt(i))\n"
"		{\n"
"			case '\\\\':\n"
"				i++;\n"
"				if (i >= length) return res;\n"
"				res += fmt.charAt(i);\n"
"				break;\n"
"			case 'X':\n"
"				m = val.match(/\\w/);\n"
"				if (!m) return res;\n"
"				res += MuPDF.convertCase(m[0],cs);\n"
"				val = val.replace(/^\\W*\\w/,'');\n"
"				break;\n"
"			case 'A':\n"
"				m = val.match(/[A-Za-z]/);\n"
"				if (!m) return res;\n"
"				res += MuPDF.convertCase(m[0],cs);\n"
"				val = val.replace(/^[^A-Za-z]*[A-Za-z]/,'');\n"
"				break;\n"
"			case '9':\n"
"				m = val.match(/\\d/);\n"
"				if (!m) return res;\n"
"				res += m[0];\n"
"				val = val.replace(/^\\D*\\d/,'');\n"
"				break;\n"
"			case '*':\n"
"				res += val;\n"
"				val = '';\n"
"				break;\n"
"			case '?':\n"
"				if (!val) return res;\n"
"				res += MuPDF.convertCase(val.charAt(0),cs);\n"
"				val = val.substring(1);\n"
"				break;\n"
"			case '=':\n"
"			case '>':\n"
"			case '<':\n"
"				cs = fmt.charAt(i);\n"
"				break;\n"
"			default:\n"
"				res += MuPDF.convertCase(fmt.charAt(i),cs);\n"
"				break;\n"
"		}\n"
"		i++;\n"
"	}\n"
"	return res;\n"
"}\n"
"util.printf = function()\n"
"{\n"
"	var i;\n"
"	if (arguments.length < 1)\n"
"		return \"\";\n"
"	var res = \"\";\n"
"	var arg_i = 1;\n"
"	var regexp = /%[^dfsx]*[dfsx]|[^%]*/g;\n"
"	var tokens = arguments[0].match(regexp);\n"
"	var length = tokens ? tokens.length : 0;\n"
"	for (i = 0; i < length; i++)\n"
"	{\n"
"		var tok = tokens[i];\n"
"		if (tok.match(/^%/))\n"
"		{\n"
"			if (arg_i < arguments.length)\n"
"			{\n"
"				var val = arguments[arg_i++];\n"
"				var fval = '';\n"
"				var neg = false;\n"
"				var decsep_re = /^,[0123]/;\n"
"				var flags_re = /^[+ 0#]+/;\n"
"				var width_re = /^\\d+/;\n"
"				var prec_re = /^\\.\\d+/;\n"
"				var conv_re = /^[dfsx]/;\n"
"				tok = tok.replace(/^%/, \"\");\n"
"				var decsep = tok.match(decsep_re);\n"
"				if (decsep) decsep = decsep[0];\n"
"				tok = tok.replace(decsep_re, \"\");\n"
"				var flags = tok.match(flags_re);\n"
"				if (flags) flags = flags[0];\n"
"				tok = tok.replace(flags_re, \"\");\n"
"				var width = tok.match(width_re);\n"
"				if (width) width = width[0];\n"
"				tok = tok.replace(width_re, \"\");\n"
"				var prec = tok.match(prec_re);\n"
"				if (prec) prec = prec[0];\n"
"				tok = tok.replace(prec_re, \"\");\n"
"				var conv = tok.match(conv_re);\n"
"				if (conv) conv = conv[0];\n"
"				prec = prec ? Number(prec.replace(/^\\./, '')) : 0;\n"
"				var poschar = (flags && flags.match(/[+ ]/)) ? flags.match(/[+ ]/)[0] : '';\n"
"				var pad = (flags && flags.match(/0/)) ? '0' : ' ';\n"
"				var point = '.';\n"
"				var thou = '';\n"
"				if (decsep)\n"
"				{\n"
"					switch(decsep)\n"
"					{\n"
"						case ',0': thou = ','; break;\n"
"						case ',1': break;\n"
"						case ',2': thou = '.'; point = ','; break;\n"
"						case ',3': point = ','; break;\n"
"					}\n"
"				}\n"
"				switch(conv)\n"
"				{\n"
"					case 'x':\n"
"						val = Math.floor(val);\n"
"						neg = (val < 0);\n"
"						if (neg)\n"
"							val = -val;\n"
"						// Convert to hex\n"
"						while (val)\n"
"						{\n"
"							fval = '0123456789ABCDEF'.charAt(val%16) + fval;\n"
"							val = Math.floor(val/16);\n"
"						}\n"
"						if (neg)\n"
"							fval = '-' + fval;\n"
"						else\n"
"							fval = poschar + fval;\n"
"						break;\n"
"					case 'd':\n"
"						fval = String(Math.floor(val));\n"
"						break;\n"
"					case 's':\n"
"						// Always pad strings with space\n"
"						pad = ' ';\n"
"						fval = String(val);\n"
"						break;\n"
"					case 'f':\n"
"						fval = String(val);\n"
"						if (prec)\n"
"						{\n"
"							var frac = fval.match(/\\.\\d+/);\n"
"							if (frac)\n"
"							{\n"
"								frac = frac[0];\n"
"								// Matched string includes the dot, so make it\n"
"								// prec+1 in length\n"
"								if (frac.length > prec+1)\n"
"									frac = frac.substring(0, prec+1);\n"
"								else if(frac.length < prec+1)\n"
"									frac += new Array(prec+1-frac.length+1).join('0');\n"
"								fval = fval.replace(/\\.\\d+/, frac);\n"
"							}\n"
"						}\n"
"						break;\n"
"				}\n"
"				if (conv.match(/[fd]/))\n"
"				{\n"
"					if (fval >= 0)\n"
"						fval = poschar + fval;\n"
"					if (point !== '.')\n"
"						fval.replace(/\\./, point);\n"
"					if (thou)\n"
"					{\n"
"						var intpart = fval.match(/\\d+/)[0];\n"
"						intpart = new Array(2-(intpart.length+2)%3+1).join('0') + intpart;\n"
"						intpart = intpart.match(/.../g).join(thou).replace(/^0*[,.]?/,'');\n"
"						fval = fval.replace(/\\d+/, intpart);\n"
"					}\n"
"				}\n"
"				if (width && fval.length < width)\n"
"					fval = new Array(width - fval.length + 1).join(pad) + fval;\n"
"				res += fval;\n"
"			}\n"
"		}\n"
"		else\n"
"		{\n"
"			res += tok;\n"
"		}\n"
"	}\n"
"	return res;\n"
"}\n"
"function AFMergeChange(event)\n"
"{\n"
"	return event.value;\n"
"}\n"
"function AFMakeNumber(str)\n"
"{\n"
"	var nums = str.match(/\\d+/g);\n"
"	if (!nums)\n"
"		return null;\n"
"	var res = nums.join('.');\n"
"	if (str.match(/^[^0-9]*\\./))\n"
"		res = '0.'+res;\n"
"	return res * (str.match(/-/) ? -1.0 : 1.0);\n"
"}\n"
"function AFExtractTime(dt)\n"
"{\n"
"	var ampm = dt.match(/(am|pm)/);\n"
"	dt = dt.replace(/(am|pm)/, '');\n"
"	var t = dt.match(/\\d{1,2}:\\d{1,2}:\\d{1,2}/);\n"
"	dt = dt.replace(/\\d{1,2}:\\d{1,2}:\\d{1,2}/, '');\n"
"	if (!t)\n"
"	{\n"
"		t = dt.match(/\\d{1,2}:\\d{1,2}/);\n"
"		dt = dt.replace(/\\d{1,2}:\\d{1,2}/, '');\n"
"	}\n"
"	return [dt, t?t[0]+(ampm?ampm[0]:''):''];\n"
"}\n"
"function AFParseDateOrder(fmt)\n"
"{\n"
"	var i;\n"
"	var order = '';\n"
"	// Ensure all present with those not added in default order\n"
"	fmt += \"mdy\";\n"
"	for (i = 0; i < fmt.length; i++)\n"
"	{\n"
"		var c = fmt.charAt(i);\n"
"		if ('ymd'.indexOf(c) !== -1 && order.indexOf(c) === -1)\n"
"			order += c;\n"
"	}\n"
"	return order;\n"
"}\n"
"function AFMatchMonth(d)\n"
"{\n"
"	var m = d.match(MuPDF.monthPattern);\n"
"	return m ? MuPDF.shortMonthName.indexOf(m[0]) : null;\n"
"}\n"
"function AFParseTime(str, d)\n"
"{\n"
"	if (!str)\n"
"		return d;\n"
"	if (!d)\n"
"		d = new Date();\n"
"	var ampm = str.match(/(am|pm)/);\n"
"	var nums = str.match(/\\d+/g);\n"
"	var hour, min, sec;\n"
"	if (!nums)\n"
"		return null;\n"
"	sec = 0;\n"
"	switch (nums.length)\n"
"	{\n"
"		case 3:\n"
"			sec = parseInt(nums[2]);\n"
"		case 2:\n"
"			hour = parseInt(nums[0]);\n"
"			min = parseInt(nums[1]);\n"
"			break;\n"
"		default:\n"
"			return null;\n"
"	}\n"
"	ampm = ampm && ampm[0]\n"
"	if (ampm === 'am' && hour < 12)\n"
"		hour = 12 + hour;\n"
"	if (ampm === 'pm' && hour >= 12)\n"
"		hour = 0 + hour - 12;\n"
"	d.setHours(hour, min, sec);\n"
"	if (d.getHours() !== hour || d.getMinutes() !== min || d.getSeconds() !== sec)\n"
"		return null;\n"
"	return d;\n"
"}\n"
"function AFParseDateEx(d, fmt)\n"
"{\n"
"	var i;\n"
"	var dt = AFExtractTime(d);\n"
"	var nums = dt[0].match(/\\d+/g);\n"
"	var order = AFParseDateOrder(fmt);\n"
"	var text_month = AFMatchMonth(dt[0]);\n"
"	var dout = new Date();\n"
"	var year = dout.getFullYear();\n"
"	var month = dout.getMonth();\n"
"	var date = dout.getDate();\n"
"	dout.setHours(12,0,0);\n"
"	if (!nums || nums.length < 1 || nums.length > 3)\n"
"		return null;\n"
"	if (nums.length < 3 && text_month)\n"
"	{\n"
"		// Use the text month rather than one of the numbers\n"
"		month = text_month;\n"
"		order = order.replace('m','');\n"
"	}\n"
"	order = order.substring(0, nums.length);\n"
"	// If year and month specified but not date then use the 1st\n"
"	if (order === \"ym\" || (order === \"y\" && text_month))\n"
"		date = 1;\n"
"	for (i = 0; i < nums.length; i++)\n"
"	{\n"
"		switch (order.charAt(i))\n"
"		{\n"
"			case 'y': year = parseInt(nums[i]); break;\n"
"			case 'm': month = parseInt(nums[i]) - 1; break;\n"
"			case 'd': date = parseInt(nums[i]); break;\n"
"		}\n"
"	}\n"
"	if (year < 100)\n"
"	{\n"
"		if (fmt.search(\"yyyy\") !== -1)\n"
"			return null;\n"
"		if (year >= 50)\n"
"			year = 1900 + year;\n"
"		else if (year >= 0)\n"
"			year = 2000 + year;\n"
"	}\n"
"	dout.setFullYear(year, month, date);\n"
"	if (dout.getFullYear() !== year || dout.getMonth() !== month || dout.getDate() !== date)\n"
"		return null;\n"
"	return AFParseTime(dt[1], dout);\n"
"}\n"
"function AFDate_KeystrokeEx(fmt)\n"
"{\n"
"	if (event.willCommit && !AFParseDateEx(event.value, fmt))\n"
"	{\n"
"		app.alert(\"The date/time entered (\"+event.value+\") does not match the format (\"+fmt+\") of the field [ \"+event.target.name+\" ]\");\n"
"		event.rc = false;\n"
"	}\n"
"}\n"
"function AFDate_Keystroke(index)\n"
"{\n"
"	var formats = ['m/d','m/d/yy','mm/dd/yy','mm/yy','d-mmm','d-mmm-yy','dd-mm-yy','yy-mm-dd',\n"
"				'mmm-yy','mmmm-yy','mmm d, yyyy','mmmm d, yyyy','m/d/yy h:MM tt','m/d/yy HH:MM'];\n"
"	AFDate_KeystrokeEx(formats[index]);\n"
"}\n"
"function AFDate_FormatEx(fmt)\n"
"{\n"
"	var d = AFParseDateEx(event.value, fmt);\n"
"	event.value = d ? util.printd(fmt, d) : \"\";\n"
"}\n"
"function AFDate_Format(index)\n"
"{\n"
"	var formats = ['m/d','m/d/yy','mm/dd/yy','mm/yy','d-mmm','d-mmm-yy','dd-mm-yy','yy-mm-dd',\n"
"				'mmm-yy','mmmm-yy','mmm d, yyyy','mmmm d, yyyy','m/d/yy h:MM tt','m/d/yy HH:MM'];\n"
"	AFDate_FormatEx(formats[index]);\n"
"}\n"
"function AFTime_Keystroke(index)\n"
"{\n"
"	if (event.willCommit && !AFParseTime(event.value, null))\n"
"	{\n"
"		app.alert(\"The value entered (\"+event.value+\") does not match the format of the field [ \"+event.target.name+\" ]\");\n"
"		event.rc = false;\n"
"	}\n"
"}\n"
"function AFTime_FormatEx(fmt)\n"
"{\n"
"	var d = AFParseTime(event.value, null);\n"
"	event.value = d ? util.printd(fmt, d) : '';\n"
"}\n"
"function AFTime_Format(index)\n"
"{\n"
"	var formats = ['HH:MM','h:MM tt','HH:MM:ss','h:MM:ss tt'];\n"
"	AFTime_FormatEx(formats[index]);\n"
"}\n"
"function AFSpecial_KeystrokeEx(fmt)\n"
"{\n"
"	var cs = '=';\n"
"	var val = event.value;\n"
"	var res = '';\n"
"	var i = 0;\n"
"	var m;\n"
"	var length = fmt ? fmt.length : 0;\n"
"	while (i < length)\n"
"	{\n"
"		switch (fmt.charAt(i))\n"
"		{\n"
"			case '\\\\':\n"
"				i++;\n"
"				if (i >= length)\n"
"					break;\n"
"				res += fmt.charAt(i);\n"
"				if (val && val.charAt(0) === fmt.charAt(i))\n"
"					val = val.substring(1);\n"
"				break;\n"
"			case 'X':\n"
"				m = val.match(/^\\w/);\n"
"				if (!m)\n"
"				{\n"
"					event.rc = false;\n"
"					break;\n"
"				}\n"
"				res += MuPDF.convertCase(m[0],cs);\n"
"				val = val.substring(1);\n"
"				break;\n"
"			case 'A':\n"
"				m = val.match(/^[A-Za-z]/);\n"
"				if (!m)\n"
"				{\n"
"					event.rc = false;\n"
"					break;\n"
"				}\n"
"				res += MuPDF.convertCase(m[0],cs);\n"
"				val = val.substring(1);\n"
"				break;\n"
"			case '9':\n"
"				m = val.match(/^\\d/);\n"
"				if (!m)\n"
"				{\n"
"					event.rc = false;\n"
"					break;\n"
"				}\n"
"				res += m[0];\n"
"				val = val.substring(1);\n"
"				break;\n"
"			case '*':\n"
"				res += val;\n"
"				val = '';\n"
"				break;\n"
"			case '?':\n"
"				if (!val)\n"
"				{\n"
"					event.rc = false;\n"
"					break;\n"
"				}\n"
"				res += MuPDF.convertCase(val.charAt(0),cs);\n"
"				val = val.substring(1);\n"
"				break;\n"
"			case '=':\n"
"			case '>':\n"
"			case '<':\n"
"				cs = fmt.charAt(i);\n"
"				break;\n"
"			default:\n"
"				res += fmt.charAt(i);\n"
"				if (val && val.charAt(0) === fmt.charAt(i))\n"
"					val = val.substring(1);\n"
"				break;\n"
"		}\n"
"		i++;\n"
"	}\n"
"	if (event.rc)\n"
"		event.value = res;\n"
"	else if (event.willCommit)\n"
"		app.alert(\"The value entered (\"+event.value+\") does not match the format of the field [ \"+event.target.name+\" ] should be \"+fmt);\n"
"}\n"
"function AFSpecial_Keystroke(index)\n"
"{\n"
"	if (event.willCommit)\n"
"	{\n"
"		switch (index)\n"
"		{\n"
"			case 0:\n"
"				if (!event.value.match(/^\\d{5}$/))\n"
"					event.rc = false;\n"
"				break;\n"
"			case 1:\n"
"				if (!event.value.match(/^\\d{5}[-. ]?\\d{4}$/))\n"
"					event.rc = false;\n"
"				break;\n"
"			case 2:\n"
"				if (!event.value.match(/^((\\(\\d{3}\\)|\\d{3})[-. ]?)?\\d{3}[-. ]?\\d{4}$/))\n"
"					event.rc = false;\n"
"				break;\n"
"			case 3:\n"
"				if (!event.value.match(/^\\d{3}[-. ]?\\d{2}[-. ]?\\d{4}$/))\n"
"					event.rc = false;\n"
"				break;\n"
"		}\n"
"		if (!event.rc)\n"
"			app.alert(\"The value entered (\"+event.value+\") does not match the format of the field [ \"+event.target.name+\" ]\");\n"
"	}\n"
"}\n"
"function AFSpecial_Format(index)\n"
"{\n"
"	var res;\n"
"	switch (index)\n"
"	{\n"
"		case 0:\n"
"			res = util.printx('99999', event.value);\n"
"			break;\n"
"		case 1:\n"
"			res = util.printx('99999-9999', event.value);\n"
"			break;\n"
"		case 2:\n"
"			res = util.printx('9999999999', event.value);\n"
"			res = util.printx(res.length >= 10 ? '(999) 999-9999' : '999-9999', event.value);\n"
"			break;\n"
"		case 3:\n"
"			res = util.printx('999-99-9999', event.value);\n"
"			break;\n"
"	}\n"
"	event.value = res ? res : '';\n"
"}\n"
"function AFNumber_Keystroke(nDec, sepStyle, negStyle, currStyle, strCurrency, bCurrencyPrepend)\n"
"{\n"
"	if (sepStyle & 2)\n"
"	{\n"
"		if (!event.value.match(/^[+-]?\\d*[,.]?\\d*$/))\n"
"			event.rc = false;\n"
"	}\n"
"	else\n"
"	{\n"
"		if (!event.value.match(/^[+-]?\\d*\\.?\\d*$/))\n"
"			event.rc = false;\n"
"	}\n"
"	if (event.willCommit)\n"
"	{\n"
"		if (!event.value.match(/\\d/))\n"
"			event.rc = false;\n"
"		if (!event.rc)\n"
"			app.alert(\"The value entered (\"+event.value+\") does not match the format of the field [ \"+event.target.name+\" ]\");\n"
"	}\n"
"}\n"
"function AFNumber_Format(nDec,sepStyle,negStyle,currStyle,strCurrency,bCurrencyPrepend)\n"
"{\n"
"	var val = event.value;\n"
"	var fracpart;\n"
"	var intpart;\n"
"	var point = sepStyle&2 ? ',' : '.';\n"
"	var separator = sepStyle&2 ? '.' : ',';\n"
"	if (/^\\D*\\./.test(val))\n"
"		val = '0'+val;\n"
"	var groups = val.match(/\\d+/g);\n"
"	if (!groups)\n"
"		return;\n"
"	switch (groups.length)\n"
"	{\n"
"		case 0:\n"
"			return;\n"
"		case 1:\n"
"			fracpart = '';\n"
"			intpart = groups[0];\n"
"			break;\n"
"		default:\n"
"			fracpart = groups.pop();\n"
"			intpart = groups.join('');\n"
"			break;\n"
"	}\n"
"	// Remove leading zeros\n"
"	intpart = intpart.replace(/^0*/,'');\n"
"	if (!intpart)\n"
"		intpart = '0';\n"
"	if ((sepStyle & 1) === 0)\n"
"	{\n"
"		// Add the thousands sepearators: pad to length multiple of 3 with zeros,\n"
"		// split into 3s, join with separator, and remove the leading zeros\n"
"		intpart = new Array(2-(intpart.length+2)%3+1).join('0') + intpart;\n"
"		intpart = intpart.match(/.../g).join(separator).replace(/^0*/,'');\n"
"	}\n"
"	if (!intpart)\n"
"		intpart = '0';\n"
"	// Adjust fractional part to correct number of decimal places\n"
"	fracpart += new Array(nDec+1).join('0');\n"
"	fracpart = fracpart.substring(0,nDec);\n"
"	if (fracpart)\n"
"		intpart += point+fracpart;\n"
"	if (bCurrencyPrepend)\n"
"		intpart = strCurrency+intpart;\n"
"	else\n"
"		intpart += strCurrency;\n"
"	if (/-/.test(val))\n"
"	{\n"
"		switch (negStyle)\n"
"		{\n"
"			case 0:\n"
"				intpart = '-'+intpart;\n"
"				break;\n"
"			case 1:\n"
"				break;\n"
"			case 2:\n"
"			case 3:\n"
"				intpart = '('+intpart+')';\n"
"				break;\n"
"		}\n"
"	}\n"
"	if (negStyle&1)\n"
"		event.target.textColor = /-/.test(val) ? color.red : color.black;\n"
"	event.value = intpart;\n"
"}\n"
"function AFPercent_Keystroke(nDec, sepStyle)\n"
"{\n"
"	AFNumber_Keystroke(nDec, sepStyle, 0, 0, \"\", true);\n"
"}\n"
"function AFPercent_Format(nDec, sepStyle)\n"
"{\n"
"	var val = AFMakeNumber(event.value);\n"
"	if (!val)\n"
"	{\n"
"		event.value = '';\n"
"		return;\n"
"	}\n"
"	event.value = (val * 100) + '';\n"
"	AFNumber_Format(nDec, sepStyle, 0, 0, \"%\", false);\n"
"}\n"
"function AFSimple_Calculate(op, list)\n"
"{\n"
"	var i, res;\n"
"	switch (op)\n"
"	{\n"
"		case 'SUM':\n"
"			res = 0;\n"
"			break;\n"
"		case 'PRD':\n"
"			res = 1;\n"
"			break;\n"
"		case 'AVG':\n"
"			res = 0;\n"
"			break;\n"
"	}\n"
"	if (typeof list === 'string')\n"
"		list = list.split(/ *, */);\n"
"	for (i = 0; i < list.length; i++)\n"
"	{\n"
"		var field = getField(list[i]);\n"
"		var value = Number(field.value);\n"
"		switch (op)\n"
"		{\n"
"			case 'SUM':\n"
"				res += value;\n"
"				break;\n"
"			case 'PRD':\n"
"				res *= value;\n"
"				break;\n"
"			case 'AVG':\n"
"				res += value;\n"
"				break;\n"
"			case 'MIN':\n"
"				if (i === 0 || value < res)\n"
"					res = value;\n"
"				break;\n"
"			case 'MAX':\n"
"				if (i === 0 || value > res)\n"
"					res = value;\n"
"				break;\n"
"		}\n"
"	}\n"
"	if (op === 'AVG')\n"
"		res /= list.length;\n"
"	event.value = res;\n"
"}\n"
"function AFRange_Validate(lowerCheck, lowerLimit, upperCheck, upperLimit)\n"
"{\n"
"	if (upperCheck && event.value > upperLimit)\n"
"	{\n"
"		event.rc = false;\n"
"	}\n"
"	if (lowerCheck && event.value < lowerLimit)\n"
"	{\n"
"		event.rc = false;\n"
"	}\n"
"	if (!event.rc)\n"
"	{\n"
"		if (lowerCheck && upperCheck)\n"
"			app.alert(util.printf(\"The entered value (\"+event.value+\") must be greater than or equal to %s and less than or equal to %s\", lowerLimit, upperLimit));\n"
"		else if (lowerCheck)\n"
"			app.alert(util.printf(\"The entered value (\"+event.value+\") must be greater than or equal to %s\", lowerLimit));\n"
"		else\n"
"			app.alert(util.printf(\"The entered value (\"+event.value+\") must be less than or equal to %s\", upperLimit));\n"
"	}\n"
"}\n"
