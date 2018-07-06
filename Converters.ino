int convertASCtoINT(uint8_t value)
{
	if (value - 48 > 9) {
		value -= 55;
	}
	else {
		value -= 48;
	}
	return value;
}
