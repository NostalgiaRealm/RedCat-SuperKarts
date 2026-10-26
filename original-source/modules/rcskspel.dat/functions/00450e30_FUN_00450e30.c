/*
 * FUN_00450e30 at 00450e30
 * undefined FUN_00450e30(void)
 * Address ranges: 00450e30-00450f74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00450e30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_004afce0(s_CBonusController__InitTypes_004f1268);
  FUN_00454520(7,param_2);
  FUN_00454520(1,param_3);
  FUN_00454520(2,param_3);
  FUN_00454520(3,param_4);
  FUN_00454520(4,param_4);
  FUN_00454520(5,param_5);
  FUN_00454520(6,param_6);
  if ((char)param_2 != '\0') {
    FUN_00450760(5);
  }
  if ((char)param_3 != '\0') {
    FUN_00450760(1);
  }
  if ((char)param_4 != '\0') {
    FUN_00450760(2);
  }
  if ((char)param_5 != '\0') {
    FUN_00450760(3);
  }
  if ((char)param_6 != '\0') {
    FUN_00450760(4);
  }
  iVar3 = 0;
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x30))();
  if (0 < iVar1) {
    do {
      uVar2 = FUN_0044fb50();
      switch(uVar2) {
      case 0:
        break;
      case 1:
      case 2:
        if ((char)param_3 == '\0') break;
        uVar2 = 2;
        goto LAB_00450f4d;
      case 3:
      case 4:
        if ((char)param_4 != '\0') {
          uVar2 = 2;
          goto LAB_00450f4d;
        }
        break;
      case 5:
        if ((char)param_5 != '\0') {
          uVar2 = 2;
          goto LAB_00450f4d;
        }
        break;
      case 6:
        if ((char)param_6 != '\0') {
          uVar2 = 2;
          goto LAB_00450f4d;
        }
        break;
      case 7:
        if ((char)param_2 != '\0') {
          uVar2 = 2;
          goto LAB_00450f4d;
        }
        break;
      default:
        goto switchD_00450f0c_default;
      }
      uVar2 = 1;
LAB_00450f4d:
      FUN_0044fa70(uVar2);
switchD_00450f0c_default:
      iVar3 = iVar3 + 1;
      iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x30))();
    } while (iVar3 < iVar1);
  }
  FUN_004afce0(s_CBonusController__InitTypes_done_004f1288);
  return;
}

