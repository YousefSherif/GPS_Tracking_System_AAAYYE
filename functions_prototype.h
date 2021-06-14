
void portF_init(void);
uint32_t portF_input(void);
void portF_output(uint32_t data);
double distance_m (double lat1, double long1,double lat2, double long2);	


//leds
void LCD_init(void);
void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_GotoXY(uint8_t _x, uint8_t _y);
void LCD_WriteString(char *_Str);
void delay_milli(int n);
void LCD_WriteDouble(double d);



//UART intitialization
void UART2Init(void);
char* UART2_ReadStr(void);
void UART2_write(char c);
char UART2_read(void);

	

//GPS
double gps_coord_lat (char *gps_data);
double gps_coord_long (char *gps_data);
double true_coord (double in);
double GPGGA_lat(char *gps_data);
double GPGGA_long(char *gps_data);




//conversion 
double convert_string_to_double (char *string);


void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);



//timer
void Systick_Wait_1ms (void);
void Systick_Wait_Multiples_1ms(uint32_t time);



