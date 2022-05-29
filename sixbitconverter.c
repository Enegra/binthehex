#include <stdio.h>
#include <string.h>

int getDecimalValue(char c) {
    int decimal = 0;
    if (c >= '0' && c <= '9') {
        decimal = c - 48;
    } else if (c >= 'a' && c <= 'f') {
        decimal = c - 87;
    } else if (c >= 'A' && c <= 'F') {
        decimal = c - 55;
    }
    return decimal;
}

void convertToBinary(int decValue, int *binValues){
    int dividend = decValue;
    for (int i = 3; i >= 0; i--) {
        int remainder = dividend % 2;
        binValues[i] = remainder;
        dividend = dividend / 2;
    }
}

int main(void)
{
    int length;
    char sample[] = "C100095814CB271DF4C33D20820401A080808080050180830105324160CD698000000000E0040150A52A32CE0000000000000000000000000000000000000000000000001F010000";

    printf("%s\n", sample);
    length = strlen(sample);
    int binaryValues[length * 4];
    // because one hexadecimal is up to 4 bits

    for (int i = 0; i < length; i++)
    {
        int binValues[4];
        int dec = getDecimalValue(sample[i]);
        convertToBinary(dec, binValues);
        int offset = i * 4;
        for (int j = 0; j < 4; j++) {
            binaryValues[offset + j] = binValues[j];
        }
        printf("%d", binaryValues[i]);
    }

    length = length * 4;

    char result[length/6];
    for (int i=0; i < length; i+=6){
        int decimalValue = 0;
        if (binaryValues[i] == 0){
            decimalValue = 1;
        }
        for (int j=0; j<6; j++){
            int currentValue = binaryValues[i + j];
            decimalValue = decimalValue*2 + currentValue;
        }
        printf("%s%d\n", "Decimal value: ", decimalValue);
        strcat(result, &decimalValue);
    }
//
    printf(result);
    return 0;
}

