/*
 * FUN_004106b0 at 004106b0
 * undefined FUN_004106b0(void)
 * Address ranges: 004106b0-004107ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004106b0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float10 fVar5;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ccdb8;
  local_c = ExceptionList;
  if (param_1 == -1) {
    ExceptionList = &local_c;
    FUN_004513c0();
    iVar2 = FUN_00451f70();
    fVar5 = (float10)FUN_0048f4d0();
    iVar3 = FUN_00435a30();
    *(float *)(iVar3 + 0x100) = (float)(fVar5 + (float10)((float)iVar2 * 0.001));
  }
  else {
    ExceptionList = &local_c;
    FUN_004513c0();
    iVar2 = FUN_00451f70();
    fVar5 = (float10)FUN_0048f4d0();
    *(float *)(&DAT_00503ff0 + param_1 * 0x11c) = (float)(fVar5 + (float10)((float)iVar2 * 0.001));
  }
  uVar4 = FUN_00438270(local_1c);
  local_4 = 0;
  FUN_004387a0(param_1,uVar4);
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

