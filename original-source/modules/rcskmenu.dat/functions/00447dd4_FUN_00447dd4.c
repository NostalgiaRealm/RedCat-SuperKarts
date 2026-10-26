/*
 * FUN_00447dd4 at 00447dd4
 * undefined __register FUN_00447dd4(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00447dd4-00447fda
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447dd4(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar3;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  
  if (*(char *)(*(int *)(param_1 + 0x14) + 0x10) == '\x01') {
    iVar1 = *(int *)(*(int *)(param_4 + -4) + 4);
    param_2 = *(int *)(param_1 + 0x20);
    if (iVar1 <= param_2) {
      iVar3 = *(int *)(param_4 + -8);
      param_2 = param_2 - *(int *)(iVar3 + 0xc);
      if (param_2 <= iVar1) {
        **(undefined4 **)(param_4 + -0xc) = 0x12;
        *(int *)(param_4 + -0x10) = param_1;
        goto LAB_00447f9e;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(char *)(iVar3 + 0x10) == '\x02') {
    param_2 = *(int *)(param_1 + 0x20);
    if (**(int **)(param_4 + -4) <= param_2) {
      iVar3 = *(int *)(param_4 + -8);
      param_2 = param_2 - *(int *)(iVar3 + 0xc);
      if (param_2 <= **(int **)(param_4 + -4)) {
        **(undefined4 **)(param_4 + -0xc) = 0x12;
        *(int *)(param_4 + -0x10) = param_1;
        goto LAB_00447f9e;
      }
    }
  }
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = FUN_004472ac(param_1,'\x01');
    iVar2 = FUN_004472ac(param_1,'\x02');
    iVar3 = extraout_ECX;
    param_2 = extraout_EDX;
    if (*(char *)(*(int *)(param_4 + -8) + 0x1c) == '\0') {
      if (((iVar2 <= **(int **)(param_4 + -4)) &&
          (param_2 = *(int *)(param_4 + -8),
          **(int **)(param_4 + -4) <= iVar2 + *(int *)(param_2 + 0x18))) &&
         (iVar1 <= *(int *)(*(int *)(param_4 + -4) + 4))) {
        iVar2 = FUN_00447318(param_1,'\x01');
        iVar3 = extraout_ECX_01;
        param_2 = extraout_EDX_01;
        if (*(int *)(*(int *)(param_4 + -4) + 4) <= iVar1 + iVar2) {
          *(int *)(param_4 + -0x10) = param_1;
          param_2 = *(int *)(*(int *)(param_1 + 4) + 0x34) + 0xf;
          if (*(int *)(*(int *)(param_4 + -4) + 4) < param_2) {
            **(undefined4 **)(param_4 + -0xc) = 0x14;
          }
          else {
            **(undefined4 **)(param_4 + -0xc) = 2;
          }
        }
      }
    }
    else if (((iVar1 <= *(int *)(*(int *)(param_4 + -4) + 4)) &&
             (param_2 = *(int *)(param_4 + -8),
             *(int *)(*(int *)(param_4 + -4) + 4) <= iVar1 + *(int *)(param_2 + 0x18))) &&
            (iVar2 <= **(int **)(param_4 + -4))) {
      iVar1 = FUN_00447318(param_1,'\x02');
      iVar3 = extraout_ECX_00;
      param_2 = extraout_EDX_00;
      if (**(int **)(param_4 + -4) <= iVar2 + iVar1) {
        *(int *)(param_4 + -0x10) = param_1;
        param_2 = *(int *)(*(int *)(param_1 + 4) + 0x30) + *(int *)(*(int *)(param_1 + 4) + 0x38) +
                  -0xf;
        if (param_2 < **(int **)(param_4 + -4)) {
          **(undefined4 **)(param_4 + -0xc) = 0x14;
        }
        else {
          **(undefined4 **)(param_4 + -0xc) = 2;
        }
      }
    }
  }
LAB_00447f9e:
  if ((*(int *)(param_4 + -0x10) == 0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = param_4;
    FUN_00447dd4(*(int *)(param_1 + 0xc),param_2,iVar3,param_4);
    iVar3 = iVar1;
    param_2 = extraout_EDX_02;
  }
  if ((*(int *)(param_4 + -0x10) == 0) && (*(int *)(param_1 + 8) != 0)) {
    FUN_00447dd4(*(int *)(param_1 + 8),param_2,iVar3,param_4);
  }
  return;
}

