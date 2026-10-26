/*
 * FUN_0045b170 at 0045b170
 * undefined FUN_0045b170(void)
 * Address ranges: 0045b170-0045b1ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0045b170(int param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x804) = 0;
  pfVar2 = (float *)(param_1 + 4);
  iVar3 = 0x100;
  do {
    if (*(float *)(param_1 + 0x804) <= *pfVar2) {
      fVar1 = *pfVar2;
    }
    else {
      fVar1 = *(float *)(param_1 + 0x804);
    }
    pfVar2 = pfVar2 + 2;
    iVar3 = iVar3 + -1;
    *(float *)(param_1 + 0x804) = fVar1;
  } while (iVar3 != 0);
  return;
}

