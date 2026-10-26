/*
 * FUN_00488b80 at 00488b80
 * undefined FUN_00488b80(void)
 * Address ranges: 00488b80-00488c6b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00488b80(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_180;
  undefined1 auStack_17c [380];
  
  iVar4 = 0;
  bVar1 = false;
  if ((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) {
    local_180 = 0;
    iVar2 = (**(code **)*param_1)();
    if (iVar2 < 0x14) {
      if (0 < iVar2) {
        do {
          iVar3 = FUN_00488400();
          if ((iVar3 == param_2) && (local_180 = local_180 + 1, local_180 == 3)) {
            bVar1 = true;
            iVar4 = iVar2;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar2);
        if (bVar1) {
          return;
        }
      }
      FUN_00488100();
      FUN_00488f90(*(undefined4 *)(param_1[1] + 4),1,auStack_17c);
      FUN_00488210(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return;
}

