//
// This is only a SKELETON file for the "Leap" exercise. It's been provided as a
// convenience to get you started writing code faster.
//

var Year = function (input) {
    this.isLeapYear = !!(input % 100 ? !(input % 4) : !(input % 400));
};

Year.prototype.isLeap = function () {
    return this.isLeapYear;
};

module.exports = Year;
