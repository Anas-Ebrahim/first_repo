/*
 * DIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: A-I
 */



extern void DIO_VoidInit(void)
{
	DDRA=DIO_u8PORTADIR;
	DDRB=DIO_u8PORTBDIR;
	DDRC=DIO_u8PORTCDIR;
	DDRD=DIO_u8PORTDDIR;


	PORTA |= (DIO_u8PORTAVAL)&(DIO_u8PORTADIR);
	PORTB |= (DIO_u8PORTBVAL)&(DIO_u8PORTBDIR);
	PORTC |= (DIO_u8PORTCVAL)&(DIO_u8PORTCDIR);
	PORTD |= (DIO_u8PORTDVAL)&(DIO_u8PORTDIR);

}


/*Comment!: Return PORT Number */
static u8 Local_u8ReturnPortNum(u8 Copy_u8PinIdx, u8* Copy_u8PortNumber, u8* Copy_u8PinNumber)
{
		u8 Local_u8FunState=Error;

		if((Copy_u8PinIdx>=0)&&(Copy_u8PinIdx<=7))
		{
			*Copy_u8PortNumber=DIO_u8Port0;
			*Copy_u8PinNumber=Copy_u8PinIdx;
			Local_u8FunState=OK;

		}
		else if((Copy_u8PinIdx>7)&&(Copy_u8PinIdx<=15))
		{
			*Copy_u8PortNumber=DIO_u8Port1;
			*Copy_u8PinNumber=(Copy_u8PinIdx-8);
			Local_u8FunState=OK;

		}
		else if((Copy_u8PinIdx>15)&&(Copy_u8PinIdx<=23))
		{
			*Copy_u8PortNumber=DIO_u8Port2;
			*Copy_u8PinNumber=(Copy_u8PinIdx-16);
			Local_u8FunState=OK;

		}
		else if((Copy_u8PinIdx>23)&&(Copy_u8PinIdx<=31))
		{
			*Copy_u8PortNumber=DIO_u8Port3;
			*Copy_u8PinNumber=(Copy_u8PinIdx-24);
			Local_u8FunState=OK;

		}
		else
		{
			Local_u8FunState=Error;

		}

		return Local_u8FunState;

}


/*Comment!: Read Pin Value */
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx, u8* Copy_u8PtrToVal)
{
	u8 Local_u8FunState=Error;
	u8* Local_u8PortNumber;
	u8* Local_u8PinNumber;
	Local_u8FunState=Local_u8ReturnPortNum(Copy_u8PinIdx, Local_u8PortNumber, Local_u8PinNumber);

	switch (Local_u8FunState)
	{
	case OK:
	{
		switch (*Local_u8PortNumber)
		{
		case DIO_u8Port0:
		{
			*Copy_u8PtrToVal=GetBit(PINA, *Local_u8PinNumber);
			Local_u8FunState=OK;
			break;
		}

		case DIO_u8Port1:
		{
			*Copy_u8PtrToVal=GetBit(PINB, *Local_u8PinNumber);
			Local_u8FunState=OK;
			break;

		}

		case DIO_u8Port2:
		{
			*Copy_u8PtrToVal=GetBit(PINC, *Local_u8PinNumber);
			Local_u8FunState=OK;
			break;

		}

		case DIO_u8Port3:
		{
			*Copy_u8PtrToVal=GetBit(PIND, *Local_u8PinNumber);
			Local_u8FunState=OK;
			break;

		}

		default:
			Local_u8FunState=Error;
			break;

		}

		break;
	}
	case Error:
	{
		Local_u8FunState=Error;
		break;
	}
	default:
	{
		Local_u8FunState=Error;
		break;
	}
	}

	return Local_u8FunState;

}


/*Comment!: Write Pin Value */
extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx, u8 Copy_u8PinVal)
{
			u8 Local_u8FunState=Error;
			u8* Local_u8PortNumber;
			u8* Local_u8PinNumber;
			Local_u8FunState=Local_u8ReturnPortNum(Copy_u8PinIdx, Local_u8PortNumber, Local_u8PinNumber);

			switch (Local_u8FunState)
			{
			case OK:
			{
				switch (*Local_u8PortNumber)
				{
				case DIO_u8Port0:
				{
					if(Copy_u8PinVal==DIO_u8HIGH)
					{
						SetBit(PORTA, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else if(Copy_u8PinVal==DIO_u8LOW)
					{
						ClrBit(PORTA, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else
					{
						Local_u8FunState=Error;

					}

					break;
				}

				case DIO_u8Port1:
				{
					if(Copy_u8PinVal==DIO_u8HIGH)
					{
						SetBit(PORTB, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else if(Copy_u8PinVal==DIO_u8LOW)
					{
						ClrBit(PORTB, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else
					{
						Local_u8FunState=Error;

					}

					break;

				}

				case DIO_u8Port2:
				{
					if(Copy_u8PinVal==DIO_u8HIGH)
					{
						SetBit(PORTC, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else if(Copy_u8PinVal==DIO_u8LOW)
					{
						ClrBit(PORTC, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else
					{
						Local_u8FunState=Error;

					}

					break;

				}

				case DIO_u8Port3:
				{
					if(Copy_u8PinVal==DIO_u8HIGH)
					{
						SetBit(PORTD, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else if(Copy_u8PinVal==DIO_u8LOW)
					{
						ClrBit(PORTD, *Local_u8PinNumber);
						Local_u8FunState=OK;
					}
					else
					{
						Local_u8FunState=Error;

					}

						break;

				}

				default:
					Local_u8FunState=Error;
					break;

				}

				break;
			}
			case Error:
			{
				Local_u8FunState=Error;
				break;
			}
			default:
			{
				Local_u8FunState=Error;
				break;
			}
			}

			return Local_u8FunState;

}


/*Comment!: Read Port Value */
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrToVal)
{
	u8 Local_u8FunState=Error;

	switch (Copy_u8PortIdx)
	{
	case DIO_u8Port0:
	{
		*Copy_u8PtrToVal=PINA;
		Local_u8FunState=OK;
		break;
	}

	case DIO_u8Port1:
	{
		*Copy_u8PtrToVal=PINB;
		Local_u8FunState=OK;
		break;

	}

	case DIO_u8Port2:
	{
		*Copy_u8PtrToVal=PINC;
		Local_u8FunState=OK;
		break;

	}

	case DIO_u8Port3:
	{
		*Copy_u8PtrToVal=PIND;
		Local_u8FunState=OK;
		break;

	}

	default:
	{
		Local_u8FunState=Error;
		break;

	}


	}


	return Local_u8FunState;

}


/*Comment!: Write Port Value */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal)
{
	u8 Local_u8FunState=Error;

	switch (Copy_u8PortIdx)
		{
		case DIO_u8Port0:
		{
			PORTA=Copy_u8PortVal;
			Local_u8FunState=OK;
			break;
		}

		case DIO_u8Port1:
		{
			PORTB=Copy_u8PortVal;
			Local_u8FunState=OK;
			break;

		}

		case DIO_u8Port2:
		{
			PORTC=Copy_u8PortVal;
			Local_u8FunState=OK;
			break;

		}

		case DIO_u8Port3:
		{
			PORTD=Copy_u8PortVal;
			Local_u8FunState=OK;
			break;

		}

		default:
		{
			Local_u8FunState=Error;
			break;

		}

		}

		return Local_u8FunState;

}


/*Comment!: Write Pin Direction */
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx, u8 Copy_u8PinDir)
{
	u8 Local_u8FunState=Error;
	u8* Local_u8PortNumber;
	u8* Local_u8PinNumber;
	Local_u8FunState=Local_u8ReturnPortNum(Copy_u8PinIdx, Local_u8PortNumber, Local_u8PinNumber);

				switch (Local_u8FunState)
				{
				case OK:
				{
					switch (*Local_u8PortNumber)
					{
					case DIO_u8Port0:
					{
						if(Copy_u8PinDir==DIO_u8OUTPUT)
						{
							SetBit(DDRA, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else if(Copy_u8PinDir==DIO_u8INPUT)
						{
							ClrBit(DDRA, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else
						{
							Local_u8FunState=Error;

						}

						break;
					}

					case DIO_u8Port1:
					{
						if(Copy_u8PinDir==DIO_u8OUTPUT)
						{
							SetBit(DDRB, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else if(Copy_u8PinDir==DIO_u8INPUT)
						{
							ClrBit(DDRB, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else
						{
							Local_u8FunState=Error;

						}

						break;

					}

					case DIO_u8Port2:
					{
						if(Copy_u8PinDir==DIO_u8OUTPUT)
						{
							SetBit(DDRC, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else if(Copy_u8PinDir==DIO_u8INPUT)
						{
							ClrBit(DDRC, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else
						{
							Local_u8FunState=Error;

						}

						break;

					}

					case DIO_u8Port3:
					{
						if(Copy_u8PinDir==DIO_u8OUTPUT)
						{
							SetBit(DDRD, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else if(Copy_u8PinDir==DIO_u8INPUT)
						{
							ClrBit(DDRD, *Local_u8PinNumber);
							Local_u8FunState=OK;
						}
						else
						{
							Local_u8FunState=Error;

						}

							break;

					}

					default:
						Local_u8FunState=Error;
						break;

					}

					break;
				}
				case Error:
				{
					Local_u8FunState=Error;
					break;
				}
				default:
				{
					Local_u8FunState=Error;
					break;
				}
				}

				return Local_u8FunState;


}


/*Comment!: Write Port Direction */
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir)
{
	u8 Local_u8FunState=Error;

		switch (Copy_u8PortIdx)
			{
			case DIO_u8Port0:
			{
				DDRA=Copy_u8PortDir;
				Local_u8FunState=OK;
				break;
			}

			case DIO_u8Port1:
			{
				DDRB=Copy_u8PortDir;
				Local_u8FunState=OK;
				break;

			}

			case DIO_u8Port2:
			{
				DDRC=Copy_u8PortDir;
				Local_u8FunState=OK;
				break;

			}

			case DIO_u8Port3:
			{
				DDRD=Copy_u8PortDir;
				Local_u8FunState=OK;
				break;

			}

			default:
			{
				Local_u8FunState=Error;
				break;

			}

			}

			return Local_u8FunState;

}


/* Comment!: Read Pin Direction */
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx, u8* Copy_u8PtrToDir)
{

	u8 Local_u8FunState=Error;
	u8* Local_u8PortNumber;
	u8* Local_u8PinNumber;
	Local_u8FunState=Local_u8ReturnPortNum(Copy_u8PinIdx, Local_u8PortNumber, Local_u8PinNumber);

		switch (Local_u8FunState)
		{
		case OK:
		{
			switch (*Local_u8PortNumber)
			{
			case DIO_u8Port0:
			{
				*Copy_u8PtrToDir=GetBit(DDRA, *Local_u8PinNumber);
				Local_u8FunState=OK;
				break;
			}

			case DIO_u8Port1:
			{
				*Copy_u8PtrToDir=GetBit(DDRB, *Local_u8PinNumber);
				Local_u8FunState=OK;
				break;

			}

			case DIO_u8Port2:
			{
				*Copy_u8PtrToDir=GetBit(DDRC, *Local_u8PinNumber);
				Local_u8FunState=OK;
				break;

			}

			case DIO_u8Port3:
			{
				*Copy_u8PtrToDir=GetBit(DDRD, *Local_u8PinNumber);
				Local_u8FunState=OK;
				break;

			}

			default:
				Local_u8FunState=Error;
				break;

			}

			break;
		}
		case Error:
		{
			Local_u8FunState=Error;
			break;
		}
		default:
		{
			Local_u8FunState=Error;
			break;
		}
		}

		return Local_u8FunState;

}

/* Comment!: Read Port Direction */
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrToDir)
{
	u8 Local_u8FunState=Error;

		switch (Copy_u8PortIdx)
		{
		case DIO_u8Port0:
		{
			*Copy_u8PtrToDir=DDRA;
			Local_u8FunState=OK;
			break;
		}

		case DIO_u8Port1:
		{
			*Copy_u8PtrToDir=DDRB;
			Local_u8FunState=OK;
			break;

		}

		case DIO_u8Port2:
		{
			*Copy_u8PtrToDir=DDRC;
			Local_u8FunState=OK;
			break;

		}

		case DIO_u8Port3:
		{
			*Copy_u8PtrToDir=DDRD;
			Local_u8FunState=OK;
			break;

		}

		default:
		{
			Local_u8FunState=Error;
			break;

		}


		}


		return Local_u8FunState;

}
