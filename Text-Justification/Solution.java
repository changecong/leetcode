public class Solution {

    public List<String> fullJustify(String[] words, int maxWidth) {

        final int rowMaxWidth = maxWidth + 1;
        final int numberOfWords = words.length;
        List<String> result = new ArrayList<String>();

        int rowLength = 0;
        int wordsIndex = 0;
        int rowStart = 0;
        int wordsPerRow = 0;
        int spaceLeft = 0;
        int spacePerWord = 0;
        int extraSpaces = 0;

        String rowString = "";

        while (wordsIndex < numberOfWords) {

            rowStart = wordsIndex;
            rowString = "";
            rowLength = 0;

            // calculate how many words fit the row
            while (rowLength < rowMaxWidth) {

                // last line
                if (wordsIndex == numberOfWords) {
                    break;
                }

                rowLength += words[wordsIndex].length() + 1;
                wordsIndex++;
            }

            // last line
            if (wordsIndex == numberOfWords && rowLength <= rowMaxWidth) {
                while (rowStart < wordsIndex) {
                    if (rowStart == wordsIndex - 1) {
                        rowString += words[rowStart];
                    } else {
                        rowString += words[rowStart] + " ";
                    }
                    rowStart++;
                }

                if (rowString.length() < maxWidth) {
                    int numberOfSpaces = maxWidth - rowString.length();
                    for (int i = 0; i < numberOfSpaces; ++i) {
                        rowString += " ";
                    }
                }

                result.add(rowString);
                break;
            }

            if (rowLength > rowMaxWidth) {
                wordsIndex--;
                rowLength -= words[wordsIndex].length() + 1;
            }

            wordsPerRow = wordsIndex - rowStart;
            spaceLeft = rowMaxWidth - rowLength;

            if (wordsPerRow == 0) {
                result.add("");
                continue;
            }

            if (wordsPerRow == 1) {
                rowString += words[rowStart];
                for (int i = 0; i < spaceLeft; ++i) {
                    rowString += " ";
                }

                result.add(rowString);
                continue;
            }

            // calculate the space
            spacePerWord = spaceLeft / (wordsPerRow - 1);
            extraSpaces = spaceLeft % (wordsPerRow - 1);

            // build the string
            while (rowStart < wordsIndex) {
                if (rowStart == wordsIndex - 1) {
                    rowString += words[rowStart];
                } else {
                    rowString += words[rowStart] + " ";
                    for (int i = 0; i < spacePerWord; ++i) {
                        rowString += " ";
                    }

                    if (extraSpaces > 0) {
                        rowString += " ";
                        extraSpaces--;
                    }
                }

                rowStart++;
            }

            result.add(rowString);
        }

        return result;
    }
}