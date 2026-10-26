/*
 * _SmackGoto@8 at 004031d0
 * undefined __thiscall _SmackGoto@8(void * this, uint param_1, int param_2)
 * Address ranges: 004031d0-004031ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall _SmackGoto_8(void *this,uint param_1,int param_2)

{
  undefined4 extraout_ECX;
  
                    /* 0x31d0  27  _SmackGoto@8 */
  if (param_1 != 0) {
    if (param_2 != 0) {
      param_2 = param_2 + -1;
    }
    if (param_2 != *(int *)(param_1 + 0x370)) {
      *(int *)(param_1 + 0x370) = param_2;
      FUN_00405740(this,param_1);
      FUN_004053e0(extraout_ECX);
    }
  }
  return;
}

