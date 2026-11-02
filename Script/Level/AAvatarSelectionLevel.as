class AAvatarSelectionLevel : ALevelScriptActor
{
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UBodyPickWidget> BodyPickWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UFaceSelectWidget> FaceSelectWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor BodyCameraActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor FaceCameraActor;

	private UUserWidget BodyPickUserWidget;
	private UUserWidget FaceSelectUserWidget;
	private UBodyPickWidget BodyPickWidget;
	private UFaceSelectWidget FaceSelectWidget;
	private APlayerController PlayerController;
	private ATFPShooterCharacter PlayerCharacter;
	private float CameraBlendingTime = 0.5f;
	private bool bIsFaceCameraActive = false;

	UFUNCTION(BlueprintOverride)
	protected void BeginPlay()
	{
		PlayerController = Gameplay::GetPlayerController(0);
		PlayerCharacter = Cast<ATFPShooterCharacter>(PlayerController.GetControlledPawn());

		if(IsValid(PlayerController))
		{
			PlayerController.SetViewTargetWithBlend(BodyCameraActor);
			PlayerController.bShowMouseCursor = true;
		}

		if(IsValid(BodyPickWidgetClass))
		{
			BodyPickUserWidget = WidgetBlueprint::CreateWidget(BodyPickWidgetClass, PlayerController);
			BodyPickWidget = Cast<UBodyPickWidget>(BodyPickUserWidget);
			BodyPickWidget.AddToViewport();
			
		}

		if(IsValid(FaceSelectWidgetClass))
		{
			FaceSelectUserWidget = WidgetBlueprint::CreateWidget(FaceSelectWidgetClass, PlayerController);
			FaceSelectWidget = Cast<UFaceSelectWidget>(FaceSelectUserWidget);
			FaceSelectWidget.DelegateSwitchCamera.BindUFunction(this, n"SwitchCamera");
		}

	}

	UFUNCTION(BlueprintOverride)
	protected void Tick(float DeltaSeconds)
	{
		if(IsValid(PlayerController))
		{
			if(PlayerController.IsInputKeyDown(EKeys::LeftMouseButton))
			{
				float MouseX = 0.0f;
				float MouseY = 0.0f;
				PlayerController.GetMousePosition(MouseX, MouseY);
				FRotator NewRotation = FRotator(0.0f, -MouseX*0.5f, 0.0f);
				
				if(IsValid(PlayerCharacter))
				{
					PlayerCharacter.AddActorWorldRotation(NewRotation);
				}
			}
		}
	}

	

	UFUNCTION()
	void SwitchCamera()
	{
		if(bIsFaceCameraActive)
		{
			PlayerController.SetViewTargetWithBlend(BodyCameraActor, CameraBlendingTime);
			BodyPickUserWidget.AddToViewport();
			FaceSelectUserWidget.RemoveFromParent();
		}
		else
		{
			PlayerController.SetViewTargetWithBlend(FaceCameraActor, CameraBlendingTime);
			FaceSelectUserWidget.AddToViewport();
			BodyPickUserWidget.RemoveFromParent();
		}

		bIsFaceCameraActive = !bIsFaceCameraActive;
	}
}