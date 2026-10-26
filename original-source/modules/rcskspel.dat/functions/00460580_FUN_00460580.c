/*
 * FUN_00460580 at 00460580
 * undefined FUN_00460580(void)
 * Address ranges: 00460580-004606b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00460580(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cef7b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_004d2b74;
  local_4 = 1;
  if ((int *)param_1[1] != (int *)0x0) {
    (**(code **)(*(int *)param_1[1] + 4))(1);
  }
  param_1[1] = 0;
  iVar4 = (**(code **)param_1[2])();
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      iVar2 = *(int *)(*(int *)(param_1[3] + 4) + iVar5 * 4);
      if (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 0x80c);
        if (iVar3 != 0) {
          cVar1 = *(char *)(iVar3 + -1);
          if ((cVar1 == '\0') || (cVar1 == -1)) {
            FUN_004bc150((char *)(iVar3 + -1));
          }
          else {
            *(char *)(iVar3 + -1) = cVar1 + -1;
          }
        }
        *(undefined4 *)(iVar2 + 0x80c) = 0;
        *(undefined4 *)(iVar2 + 0x810) = 0;
        *(undefined4 *)(iVar2 + 0x814) = 0;
        FUN_004bc150(iVar2);
      }
      iVar5 = iVar5 + 1;
      *(undefined4 *)(*(int *)(param_1[3] + 4) + -4 + iVar5 * 4) = 0;
    } while (iVar5 < iVar4);
  }
  iVar4 = param_1[5];
  param_1[4] = &PTR_FUN_004d2b78;
  if (iVar4 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar4 + 4));
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    FUN_004bc150(iVar4);
  }
  param_1[5] = 0;
  iVar4 = param_1[3];
  param_1[2] = &PTR_FUN_004d2b88;
  if (iVar4 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar4 + 4));
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    FUN_004bc150(iVar4);
  }
  param_1[3] = 0;
  ExceptionList = pvStack_c;
  return;
}

