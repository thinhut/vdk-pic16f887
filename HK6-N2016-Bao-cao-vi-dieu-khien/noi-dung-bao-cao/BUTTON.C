int READ_BUTTON();

int READ_BUTTON(){
	if (input(ONE) == 0){
		return 1;
	}
	else
		if (input(TWO) == 0){
			return 2;
		}
		else
			if (input(THREE) == 0){
				return 3;
			}
			else 
				if (input(FOUR) == 0){
					return 4;
				}
				else
					if (input(FIVE) == 0){
						return 5;
					}
					else 
						if (input(SIX) == 0){
							return 6;
						}
						else
							if (input(SEVEN) == 0){
								return 7;
							}
							else
								if (input(EIGHT) == 0){
									return 8;
								}
								else 
									if (input(NINE) == 0){
										return 9;
									}
									else
										if (input(ZERO) == 0){
											return 0;
										}
										else
											if (input(ENTER) == 0){
												return 100;
											}
											else
												if (input(SETUP_EXIT)==0){
													return 50;
												}
												else
													return -1;
}
