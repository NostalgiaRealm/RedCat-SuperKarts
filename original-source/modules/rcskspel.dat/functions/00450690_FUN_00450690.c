/*
 * FUN_00450690 at 00450690
 * undefined FUN_00450690(void)
 * Address ranges: 00450690-004506e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450690(char *param_1)

{
  if (param_1 == (char *)0xffffffff) {
    param_1 = s_CalcObjectChunkPosition_a_Object_004f11f8;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_1,&DAT_004d5538);
  }
  FUN_00450500(DAT_006a5c38 + *(int *)((int)param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x50);
  return;
}

