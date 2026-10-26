/*
 * FUN_004016e0 at 004016e0
 * undefined FUN_004016e0(void)
 * Address ranges: 004016e0-004017a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004016e0(int param_1)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  
  cVar1 = FUN_00417e90(param_1);
  iVar2 = DAT_0053be60;
  if (cVar1 == '\0') {
    iVar2 = (&DAT_005081b8)[param_1 * 0x1c];
  }
  if ((iVar2 == 0) &&
     (30.0 <= *(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20))) {
    fVar3 = (float10)FUN_0048f4e0();
    iVar2 = FUN_004be6c9();
    if (((float)(iVar2 % 100) < (float)(fVar3 * (float10)50.0)) &&
       (*(float *)(&DAT_00503f04 + param_1 * 0x11c) < 1.0)) {
      return 1;
    }
    *(undefined4 *)(&DAT_00503f04 + param_1 * 0x11c) = 0;
  }
  return 0;
}

