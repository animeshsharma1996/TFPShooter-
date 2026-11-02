
delegate void FDelegateSwitchCamera();

class UFaceSelectWidget : UUserWidget
{
	ATFPShooterCharacter PlayerCharacter;

	UPROPERTY(meta = (BindWidget))
	UButton HairPreviousButton;

	UPROPERTY(meta = (BindWidget))
	UButton HairNextButton;

	UPROPERTY(meta = (BindWidget))
	UButton EyebrowPreviousButton;

	UPROPERTY(meta = (BindWidget))
	UButton EyebrowNextButton;

	UPROPERTY(meta = (BindWidget))
	UButton BodyButton;

	UPROPERTY(meta = (BindWidget))
	UButton BeardPreviousButton;

	UPROPERTY(meta = (BindWidget))
	UButton BeardNextButton;

	UPROPERTY(meta = (BindWidget))
	UButton FacePreviousButton;

	UPROPERTY(meta = (BindWidget))
	UButton FaceNextButton;

	FDelegateSwitchCamera DelegateSwitchCamera;

	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		PlayerCharacter = Cast<ATFPShooterCharacter>(GetOwningPlayerPawn());
	
		if(IsValid(HairPreviousButton))
		{
			HairPreviousButton.OnClicked.AddUFunction(this, n"OnHairPreviousButtonClicked");
		}

		if(IsValid(HairNextButton))
		{
			HairNextButton.OnClicked.AddUFunction(this, n"OnHairNextButtonClicked");
		}

		if(IsValid(EyebrowPreviousButton))
		{
			EyebrowPreviousButton.OnClicked.AddUFunction(this, n"OnEyebrowPreviousButtonClicked");
		}

		if(IsValid(EyebrowNextButton))
		{
			EyebrowNextButton.OnClicked.AddUFunction(this, n"OnEyebrowNextButtonClicked");
		}

		if(IsValid(BodyButton))
		{
			BodyButton.OnClicked.AddUFunction(this, n"OnBodyButtonClicked");
		}

		if(IsValid(BeardPreviousButton))
		{
			BeardPreviousButton.OnClicked.AddUFunction(this, n"OnBeardPreviousButtonClicked");
		}

		if(IsValid(BeardNextButton))
		{
			BeardNextButton.OnClicked.AddUFunction(this, n"OnBeardNextButtonClicked");
		}

		if(IsValid(FacePreviousButton))
		{
			FacePreviousButton.OnClicked.AddUFunction(this, n"OnFacePreviousButtonClicked");
		}

		if(IsValid(FaceNextButton))
		{
			FaceNextButton.OnClicked.AddUFunction(this, n"OnFaceNextButtonClicked");
		}
	}

	UFUNCTION()
	protected void OnBodyButtonClicked()
	{
		//DelegateSwitchCamera.ExecuteIfBound();
	}

	UFUNCTION()
	protected void OnHairPreviousButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.HairPrevious();
		}
	}

	UFUNCTION()
	protected void OnHairNextButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.HairNext();
		}
	}

	UFUNCTION()
	protected void OnEyebrowPreviousButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.EyebrowPrevious();
		}
	}

	UFUNCTION()
	protected void OnEyebrowNextButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.EyebrowNext();
		}
	}

	UFUNCTION()
	protected void OnBeardPreviousButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.BeardPrevious();
		}
	}

	UFUNCTION()
	protected void OnBeardNextButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.BeardNext();
		}
	}

	UFUNCTION()
	protected void OnFacePreviousButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.FacePrevious();
		}
	}

	UFUNCTION()
	protected void OnFaceNextButtonClicked()
	{
		if(IsValid(PlayerCharacter))
		{
			PlayerCharacter.FaceNext();
		}	
	}
}