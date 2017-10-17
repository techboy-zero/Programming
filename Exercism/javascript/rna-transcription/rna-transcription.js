
var dnaTranscriber = function () {
    this.dnaComplement = {
        A: 'U',
        T: 'A',
        C: 'G',
        G: 'C'
    };

    this.toRna = (dna) => {
        var rna = dna.replace(/A|T|C|G/g, (nucleotide) => {
            return this.dnaComplement[nucleotide];
        });
        var extra = rna.replace(/[AUCG]/gi, "");
        if (extra.length) throw new Error ('Invalid input');
        return rna;
    }
};

module.exports = dnaTranscriber;