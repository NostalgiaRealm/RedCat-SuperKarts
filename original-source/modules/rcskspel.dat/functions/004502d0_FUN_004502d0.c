/*
 * FUN_004502d0 at 004502d0
 * undefined FUN_004502d0(void)
 * Address ranges: 004502d0-00450321
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004502d0(int param_1,char *param_2)

{
  if (param_2 == (char *)0xffffffff) {
    param_2 = s_CBonusData__SetObject__trying_to_004f112c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  if ((char *)*(int *)(param_1 + 0xc) != param_2) {
    *(char **)(param_1 + 0xc) = param_2;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)((int)param_2 * 0xd0 + 0xc + DAT_0067ee20);
    FUN_004500e0();
    FUN_004501b0();
  }
  return;
}

