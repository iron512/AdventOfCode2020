if (process.argv.length != 3) {
	console.log("Wrong parameters passed. Please run using again using the correct syntax:\n\nnode main.js <input_file_name>\n\n")
	return;
}

var lineReader = require('readline').createInterface({
  input: require('fs').createReadStream(process.argv[2])
});

var attributes = ['byr','iyr','eyr','hgt','hcl','ecl','pid']

var pass = {}
var count1 = 0
var count2 = 0
var total = 0

lineReader.on('line', function (line) {
  if (line != "") {
  	//add elements
	line.split(" ").forEach(function(entry) {
		entry = entry.split(":")
		pass[entry[0].toString()] = entry[1]
	});
  } else {
  	//check validity
	var validity1 = true
	var validity2 = true
	//console.log(pass)
	attributes.forEach(function(entry) {
		if (!(entry in pass))
			validity1 = false
		else{
			if (entry == "byr" && !(pass[entry] >= 1920 &&  pass[entry] <= 2002)) {
				validity2 = false
			}
			
			if (entry == "iyr" && !(pass[entry] >= 2010 &&  pass[entry] <= 2020)) {
				validity2 = false
			}

			if (entry == "eyr" && !(pass[entry] >= 2020 &&  pass[entry] <= 2030)) {
				validity2 = false
			}
		
			if (entry == "ecl" && !(["amb","blu","brn","gry","grn","hzl","oth"].includes(pass[entry]))) {
				validity2 = false
			}

			if (entry == "pid" && (pass[entry].match(/^[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]$/g) == null)) {
				validity2 = false
			}

			if (entry == "hcl" && (pass[entry].match(/#[0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f]/g) == null)) {
				validity2 = false
			}

			if (entry == "hgt") {
				if (((pass[entry].match(/1[5-8][0-9]cm/g) == null) && (pass[entry].match(/19[0-3]cm/g) == null)) && ((pass[entry].match(/59in/g) == null) && (pass[entry].match(/[67][0-6]in/g) == null) && (pass[entry].match(/6[0-9]in/g) == null))) {
					validity2 = false
				}
			}
		} 
	})

	total = total +1
	if (validity1) {
		count1 = count1+1
	} 

	if (validity1 && validity2) {
		count2 = count2+1
	} 


	pass = []
  }
})

lineReader.on("close", function() {
    console.log('First valid passport count: ' + count1)
    console.log('Second valid passport count: ' + count2)
})