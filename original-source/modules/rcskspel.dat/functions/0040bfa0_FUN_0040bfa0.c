/*
 * FUN_0040bfa0 at 0040bfa0
 * undefined FUN_0040bfa0(void)
 * Address ranges: 0040bfa0-0040c00a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0040bfa0(int param_1)

{
  undefined4 uVar1;
  uint3 uVar3;
  uint uVar2;
  int iVar4;
  
  iVar4 = param_1 * 0x11c;
  uVar1 = FUN_0040eba0();
  uVar3 = (uint3)((uint)uVar1 >> 8);
  uVar2 = CONCAT31(uVar3,(&DAT_00503f64)[iVar4]);
  if ((&DAT_00503f64)[iVar4] == '\0') {
    return (uint)uVar3 << 8;
  }
  if ((-1 < *(int *)(&DAT_00503f68 + iVar4)) &&
     (uVar2 = *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20) -
              *(int *)(&DAT_00503f68 + iVar4), 0 < (int)uVar2)) {
    (&DAT_00503f64)[iVar4] = 0;
    *(undefined4 *)(&DAT_00503f68 + iVar4) = 0xffffffff;
    return uVar2 & 0xffffff00;
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}

