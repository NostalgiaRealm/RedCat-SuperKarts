/*
 * FUN_004519f8 at 004519f8
 * undefined __register FUN_004519f8(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 004519f8-00451aee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004519f8(int *param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  if (param_2 == (int *)0x0) {
    FUN_00451c90(param_1,0,param_3);
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  else {
    uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00450238);
    if ((char)uVar1 == '\0') {
      uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_004164a4);
      if ((char)uVar1 == '\0') {
        uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_00416588);
        if ((char)uVar1 == '\0') {
          FUN_0040fca8(param_1,param_2);
        }
        else {
          if ((int *)param_2[1] == (int *)0x0) {
            FUN_00451c90(param_1,extraout_EDX_00,extraout_ECX_00);
          }
          else {
            FUN_0045196c((int *)param_2[1],extraout_EDX_00,extraout_ECX_00,(int)&stack0xfffffffc);
          }
          (**(code **)(*param_1 + 0x10))(param_1,param_1);
        }
      }
      else {
        FUN_0045196c(param_2,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
        (**(code **)(*param_1 + 0x10))(param_1,param_1);
      }
    }
    else if (param_2 != param_1) {
      FUN_004524e4((int)param_1,param_2[9]);
      (**(code **)(*param_1 + 0x10))(param_1,param_1);
      uVar1 = (**(code **)(*param_2 + 0x28))();
      (**(code **)(*param_1 + 0x3c))(param_1,uVar1);
      iVar2 = FUN_00451ed0((int)param_2);
      FUN_004526fc(param_1,iVar2);
      FUN_00452714(param_1,(char)param_2[0x22]);
    }
  }
  return;
}

