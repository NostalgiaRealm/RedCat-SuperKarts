/*
 * FUN_0048a570 at 0048a570
 * undefined FUN_0048a570(void)
 * Address ranges: 0048a570-0048a6c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_0048a570(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **ppuStack_12c;
  int iStack_128;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d1522;
  local_c = ExceptionList;
  bVar1 = false;
  if ((((DAT_0053ba78 != 0) && (DAT_0053ba60 != 0)) && (DAT_0053b9b0 == 0)) &&
     (ExceptionList = &local_c, iVar2 = (**(code **)*param_1)(), iVar2 < 0x1e)) {
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        iVar3 = FUN_004895d0();
        if (iVar3 == param_2) {
          bVar1 = true;
          iVar4 = iVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
      if (bVar1) {
        ExceptionList = local_c;
        return;
      }
    }
    FUN_00489400();
    uStack_4 = 0;
    FUN_0048b610(*(undefined4 *)(param_1[1] + 4),1,&ppuStack_12c);
    FUN_004894c0(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
    ppuStack_12c = &PTR_FUN_004d2fc4;
    if (iStack_128 != 0) {
      FUN_004bc150(*(undefined4 *)(iStack_128 + 4));
      *(undefined4 *)(iStack_128 + 4) = 0;
      *(undefined4 *)(iStack_128 + 8) = 0;
      *(undefined4 *)(iStack_128 + 0xc) = 0;
      FUN_004bc150(iStack_128);
    }
  }
  ExceptionList = local_c;
  return;
}

