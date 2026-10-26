/*
 * FUN_00450330 at 00450330
 * undefined FUN_00450330(void)
 * Address ranges: 00450330-00450373
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00450330(int param_1,char *param_2)

{
  if (param_2 == (char *)0xffffffff) {
    param_2 = s_CBonusData__Set3dObject__trying_t_004f1164;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2,&DAT_004d5538);
  }
  if ((char *)*(int *)(param_1 + 8) != param_2) {
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(char **)(param_1 + 8) = param_2;
    FUN_004500e0();
    FUN_004501b0();
  }
  return;
}

