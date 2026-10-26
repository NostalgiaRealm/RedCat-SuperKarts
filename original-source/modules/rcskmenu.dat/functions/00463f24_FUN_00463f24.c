/*
 * FUN_00463f24 at 00463f24
 * undefined FUN_00463f24(void)
 * Address ranges: 00463f24-0046405c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00463f24(int *param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  HWND hWndLock;
  undefined4 extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint uVar2;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  undefined4 extraout_EDX_02;
  RECT RStack_1c;
  
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    FUN_004321e8(*(int *)PTR_DAT_0047c86c,param_2,param_3);
  }
  hWndLock = (HWND)FUN_00418994((int *)param_1[0x83]);
  LockWindowUpdate(hWndLock);
  cVar1 = FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  if ((cVar1 != '\0') && ((char)param_1[0x84] == '\0')) {
    *(undefined1 *)(param_1 + 0x84) = 1;
    FUN_00445950((int)param_1,'\x01');
    FUN_00464458(param_1);
  }
  if ((*(byte *)(param_1 + 8) & 0x10) != 0) {
    FUN_00417ea0(*(int **)(param_1[0x83] + 0x14),param_1[0x18]);
    (**(code **)(*param_1 + 0x40))(param_1,&RStack_1c);
    FUN_00418538((int *)param_1[0x83],&RStack_1c);
  }
  if (*(char *)((int)param_1 + 0x213) == '\0') {
    FUN_00417ea0(*(int **)(param_1[0x83] + 0x14),param_1[0x18]);
    (**(code **)(*param_1 + 0x40))(param_1,&RStack_1c);
    FUN_00418538((int *)param_1[0x83],&RStack_1c);
    uVar2 = extraout_ECX_01;
    uVar3 = extraout_EDX_01;
  }
  else {
    FUN_0040ebe8(param_1[0xc],param_1[0xd],param_1[0xc] + param_1[0xe],&RStack_1c.left,
                 param_1[0xd] + param_1[0xf]);
    FUN_0044e898((int *)param_1[9],&RStack_1c.left,'\0');
    uVar2 = extraout_ECX_00;
    uVar3 = extraout_EDX_00;
  }
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    FUN_004321e8(*(int *)PTR_DAT_0047c86c,uVar3,uVar2);
  }
  FUN_004630fc(param_1);
  FUN_00464288(param_1);
  cVar1 = (**(code **)(*param_1 + 0x4c))();
  if (cVar1 != '\0') {
    cVar1 = FUN_00403088(param_1,extraout_EDX_02,extraout_ECX_02);
    if ((cVar1 != '\0') && ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
      FUN_0046434c(param_1);
    }
  }
  LockWindowUpdate((HWND)0x0);
  return;
}

