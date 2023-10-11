#ifndef UPC_H
#define UPC_H

#define AV_0                            "Unassigned."
#define AV_1                            "Audio: 12\" Video CDV, Video: 12\" Video CDV."
#define AV_2                            "Audio: 3\" or 5\" CD, CD-ROM CDI and VDI, Video: Unassigned."
#define AV_3                            "Audio: Unassigned, Video: VHS."
#define AV_4                            "Audio: Cassette, Video: Unassigned."
#define AV_5                            "Audio: DCC, Video: Beta."
#define AV_6                            "Audio: Unassigned, Video: Laserdisk."
#define AV_7                            "Audio: 7\" single, Video: Unassigned."
#define AV_8                            "Audio: Mini Disc, Video: 8mm tape."
#define AV_9                            "Audio: Music DVD, Video: Video DVD."

#define UPC_MOST_PRODUCTS "General Product."
#define UPC_2             "Reserved for Local Use (Items sold by weight)."
#define UPC_3             "Drugs (By National Drug Code Number)."
#define UPC_4             "Reserved for Local Use (Coupons and Loyaltly cards)."
#define UPC_COUPONS       "Coupons."

//prototypes
int promptForUPCbarcode (int barcode_array[12]);
int convertToDigit(char c);
int foundDigitsOnly (char barcode_chars[12]);
int calculateUPCCheckDigit(int barcode_array[12]);
void display_UPC_designation(int barcode_array[12]);
char *upc_audio_visual(int barcode_array[12]);
char *upc_standard(int barcode_array[12]);
void printArray(int arr[], int size);

#endif //UPC_H
