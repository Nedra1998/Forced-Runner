#include "Libraries.h"
#include "Hephaestus.h"
using namespace std;
Hephaestus H;
void Key_Call(GLFWwindow* Win, int key, int scancode, int action, int mods){
	H.Key_Call_Back(Win, key, scancode, action, mods);
}
void Mouse_Call(GLFWwindow* Win, int button, int action, int mods){
	H.Mouse_Call_Back(Win, button, action, mods);
}
void Window_Call(GLFWwindow* Win, int width, int hight){
	glfwSetWindowSize(Win, width, hight);
}
int main(){
	GLFWwindow* Win;
	Win = H.Full_Setup();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetKeyCallback(Win, Key_Call);
	glfwSetMouseButtonCallback(Win, Mouse_Call);
	glfwSetWindowSizeCallback(Win, Window_Call);
	srand(time(NULL));
	/*>>>>>Place Before Start Code Here<<<<<*/
	int Stage = 1, Menu = 1, Page = 0;
	int Layer = -1, Button = -1, Action = -1, Update = 10;
	int M1 = 0, M2 = 0, M3 = 0;
	bool First = true;
	H.Create_New_Layer();
	H.Create_New_Layer();
	H.Create_New_Layer();
	H.Create_New_Layer();
	H.Create_New_Layer();
	while (!glfwWindowShouldClose(Win)){
		/*>>>>>Place While Running Code Here<<<<<*/
		if (First == true){
			Update = 5;
			First = false;
			if (Stage == 1){
				if (Menu == 1){
					H.Layers[0]->Initilize_Object(2);
					H.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/Sky 1", 4, 1, 1, 0, 0);
					H.Layers[5]->Clear_All();
					H.Layers[4]->Clear_All();
					H.Layers[4]->Initilize_Object(4);
					H.Layers[4]->Initilize_Object(4);
					H.Layers[4]->Initilize_Object(4);
					H.Layers[4]->Initilize_Object(4);
					H.Layers[4]->Button_Objects[0]->New_Button("FREE RUNNER", "Textures/Transparent", "Basic/Black", 0.7, 0.2);
					H.Layers[4]->Button_Objects[0]->Translate_Button(0.0, 0.8, 0.0);
					H.Layers[4]->Button_Objects[1]->New_Button("Play", "Textures/ButtonA", "Basic/Black", 0.5, 0.1);
					H.Layers[4]->Button_Objects[1]->Translate_Button(0.0, 0.3, 0.0);
					H.Layers[4]->Button_Objects[2]->New_Button("Settings", "Textures/ButtonA", "Basic/Black", 0.5, 0.1);
					H.Layers[4]->Button_Objects[2]->Translate_Button(0.0, -0.1, 0.0);
					H.Layers[4]->Button_Objects[3]->New_Button("Quit", "Textures/ButtonA", "Basic/Black", 0.5, 0.1);
					H.Layers[4]->Button_Objects[3]->Translate_Button(0.0, -0.5, 0.0);
				}
				if (Menu == 2){
					int Avalible = 0, Start = 0, Current = 0;
					float X = -0.75, Y = 0.55, x, y;
					ifstream Save("Save Data.txt");
					if (Save.is_open()){
						Save >> Avalible;
						Save.close();
					}
					H.Layers[5]->Clear_All();
					if (Page == 0 || Page == 5 || Page == 1 || Page == 4){
						H.Layers[4]->Clear_All();
						H.Layers[4]->Initilize_Object(4);
						H.Layers[4]->Button_Objects[0]->New_Button("LEVEL SELECT", "Textures/Transparent", "Basic/Black", 0.7, 0.2);
						H.Layers[4]->Button_Objects[0]->Translate_Button(0.0, 0.8, 0.0);
						H.Layers[4]->Initilize_Object(4);
						if (Page == 5){
							H.Layers[4]->Button_Objects[1]->New_Button("NEXT", "Textures/ButtonB", "Basic/Black", 0.2, 0.1);
						}
						else{
							H.Layers[4]->Button_Objects[1]->New_Button("NEXT", "Textures/ButtonA", "Basic/Black", 0.2, 0.1);
						}
						H.Layers[4]->Button_Objects[1]->Translate_Button(0.8, 0.8, 0.0);
						H.Layers[4]->Initilize_Object(4);
						if (Page == 0){
							H.Layers[4]->Button_Objects[2]->New_Button("PREVIOUS", "Textures/ButtonB", "Basic/Black", 0.2, 0.1);
						}
						else{
							H.Layers[4]->Button_Objects[2]->New_Button("PREVIOUS", "Textures/ButtonA", "Basic/Black", 0.2, 0.1);
						}
						H.Layers[4]->Button_Objects[2]->Translate_Button(-0.8, 0.8, 0.0);
						H.Layers[4]->Initilize_Object(4);
						H.Layers[4]->Button_Objects[3]->New_Button("Back", "Textures/ButtonA", "Basic/Black", 0.7, 0.1);
						H.Layers[4]->Button_Objects[3]->Translate_Button(0.0, -0.8, 0.0);
					}
					if (Page == 0){
						Start = 0;
					}
					if (Page == 1){
						Start = 36;
					}
					if (Page == 2){
						Start = 71;
					}
					if (Page == 3){
						Start = 106;
					}
					if (Page == 4){
						Start = 141;
					}
					if (Page == 5){
						Start = 176;
					}
					Current = Start;
					y = Y;
					for (int i = 0; i < 5; i++){
						x = X;
						for (int o = 0; o < 7; o++){
							H.Layers[5]->Initilize_Object(4);
							if (Current <= Avalible){
								H.Layers[5]->Button_Objects[Current - Start]->New_Button(to_string(Current + 1), "Textures/ButtonA", "Basic/Black", 0.1, 0.1);
							}
							if (Current > Avalible){
								H.Layers[5]->Button_Objects[Current - Start]->New_Button(to_string(Current + 1), "Textures/ButtonB", "Basic/Black", 0.1, 0.1);
							}
							H.Layers[5]->Button_Objects[Current - Start]->Translate_Button(x, y, 0.0);
							Current++;
							x = x + 0.25;
						}
						y = y - 0.25;
					}
					cout << "Done\n";
				}
			}
		}
		if (Stage == 1){
			float x, y;
			if (M1 < 10 && (rand() % 120) > 118){
				H.Layers[1]->Initilize_Object(2);
				x = (float ((rand() % 50)+ 30) / 100);
				y = (float ((rand() % 50) + 50) / 100);
				H.Layers[1]->Textured_Objects[M1]->New_Textured_Object("Textures/Mountain 3", 4, x, y, 0, 0);
				H.Layers[1]->Textured_Objects[M1]->Translate_Object(2, (y - 1), 0.0);
				M1++;
			}
			if (M2 < 10 && (rand() % 120) > 118){
				H.Layers[2]->Initilize_Object(2);
				x = (float((rand() % 50) + 30) / 100);
				y = (float((rand() % 50) + 40) / 100);
				H.Layers[2]->Textured_Objects[M2]->New_Textured_Object("Textures/Mountain 2", 4, x, y, 0, 0);
				H.Layers[2]->Textured_Objects[M2]->Translate_Object(2, (y - 1), 0.0);
				M2++;
			}
			if (M3 < 10 && (rand() % 120) > 118){
				H.Layers[3]->Initilize_Object(2);
				x = (float((rand() % 50) + 30) / 100);
				y = (float((rand() % 50) + 30) / 100);
				H.Layers[3]->Textured_Objects[M3]->New_Textured_Object("Textures/Mountain 1", 4, x, y, 0, 0);
				H.Layers[3]->Textured_Objects[M3]->Translate_Object(2, (y - 1), 0.0);
				M3++;
			}
		}
		for (int a = 0; a < M1; a++){
			H.Layers[1]->Textured_Objects[a]->Translate_Object(-0.01, 0.0, 0.0);
			if (H.Layers[1]->Textured_Objects[a]->Return_Float_Value(2) < -2){
				H.Layers[1]->Textured_Objects.erase(H.Layers[1]->Textured_Objects.begin() + a);
				M1--;
			}
		}
		for (int a = 0; a < M2; a++){
			H.Layers[2]->Textured_Objects[a]->Translate_Object(-0.015, 0.0, 0.0);
			if (H.Layers[2]->Textured_Objects[a]->Return_Float_Value(2) < -2){
				H.Layers[2]->Textured_Objects.erase(H.Layers[2]->Textured_Objects.begin() + a);
				M2--;
			}
		}
		for (int a = 0; a < M3; a++){
			H.Layers[3]->Textured_Objects[a]->Translate_Object(-0.02, 0.0, 0.0);
			if (H.Layers[3]->Textured_Objects[a]->Return_Float_Value(2) < -2){
				H.Layers[3]->Textured_Objects.erase(H.Layers[3]->Textured_Objects.begin() + a);
				M3--;
			}
		}
		if (Update > 0){
			Update--;
			H.Clear_Mouse();
		}
		H.Check_All_Buttons(Layer, Button, Action);
		if (Stage == 1 && Menu == 1){
			if (Layer == 4 && Button == 1){
				Menu = 2;
				Page = 0;
				First = true;
			}
			if (Layer == 4 && Button == 3){
				glfwSetWindowShouldClose(Win, 1);
			}
		}
		else if (Stage == 1 && Menu == 2){
			if (Layer == 4 && Button == 3){
				Page = 0;
				Menu = 1;
				First = true;
			}
			if (Page == 0){
				if (Layer == 4 && Button == 1){
					Page++;
					First = true;
				}
			}
			else if (Page > 0 && Page < 5){
				if (Layer == 4 && Button == 2){
					Page--;
					First = true;
				}
				if (Layer == 4 && Button == 1){
					Page++;
					First = true;
				}
			}
			else if (Page == 5){
				if (Layer == 4 && Button == 2){
					Page--;
					First = true;
				}
			}
		}
		H.Display_All_Layers();
		H.Frame();
	}
	H.Terminate_Log();
	return(0);
}