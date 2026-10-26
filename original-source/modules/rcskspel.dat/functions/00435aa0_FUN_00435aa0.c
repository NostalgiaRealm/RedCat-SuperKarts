/*
 * FUN_00435aa0 at 00435aa0
 * undefined FUN_00435aa0(void)
 * Address ranges: 00435aa0-00435c15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00435aa0(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cd26d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(char *)(param_1 + 0x11c) != '\0') {
    ExceptionList = &local_c;
    FUN_004126b0(DAT_00508610,param_1);
  }
  *(undefined1 *)(param_1 + 0x11c) = 1;
  puVar4 = (undefined4 *)(param_1 + 0xa0);
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00435850();
  uVar2 = FUN_0040c8f0();
  switch(uVar2) {
  case 1:
    uVar2 = FUN_0040c900();
    FUN_00411830(DAT_00508610,param_1,uVar2);
    break;
  case 2:
    uVar2 = FUN_0040c900();
    FUN_00411b40(DAT_00508610,param_1,uVar2);
    break;
  case 3:
    uVar2 = FUN_0040c900();
    FUN_00411e50(DAT_00508610,param_1,uVar2);
    break;
  case 4:
    uVar2 = FUN_0040c900();
    FUN_00412090(DAT_00508610,param_1,uVar2);
    break;
  default:
    *(undefined4 *)(param_1 + 0x70) = 8;
    *(undefined4 *)(param_1 + 0x98) = 0;
    FUN_0040c960(3);
    cVar1 = FUN_0040c9b0();
    if (cVar1 != '\0') {
      FUN_004afce0(s___Attacked_by_redcat_with_NOTHIN_004ebd80);
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x19;
  uVar2 = FUN_00438090(local_1c);
  local_4 = 0;
  FUN_004387a0(DAT_00508610,uVar2);
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150((char *)(local_18 + -1));
  }
  ExceptionList = local_c;
  return;
}

