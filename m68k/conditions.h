typedef void (ConditionFunc)();

void False()
{
	return 0;
}

void True()
{
	return 1;
}

ConditionFunc _conditions[] = {
	True,
	false,
	Higher,
	LowerOrSame,
	CarryClear,
	CarrySet,
	NotEqual,
	Equal,
	OverflowClear,
	OverflowSet,
	Plus,
	Minus,
	GreaterOrEqual,
	LessThan,
	GreaterThan,
	LessOrEqual
};

ConditionFunc make_condition(uint8_t pattern)
{
	// TODO handle OoB -> if (pattern > 0XF)
	return _conditions[pattern];
}
