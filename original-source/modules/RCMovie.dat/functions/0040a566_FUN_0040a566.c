/*
 * FUN_0040a566 at 0040a566
 * undefined __stdcall FUN_0040a566(void)
 * Address ranges: 0040a566-0040a615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a566(void)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  do {
    if (0x13 < local_8) {
      return;
    }
    if ((*(int *)(&DAT_0043d470 + local_8 * 8) != -1) &&
       (iVar1 = FUN_004133f0(*(uint *)(&DAT_0043d470 + local_8 * 8)), iVar1 != 0)) {
      if (*(int *)(&DAT_0043d474 + local_8 * 8) == 1) {
        DAT_0043d51c = 0;
        return;
      }
      if (*(int *)(&DAT_0043d474 + local_8 * 8) == 2) {
        DAT_0043d518 = (uint)(DAT_0043d518 == 0);
        return;
      }
      do {
        iVar1 = FUN_004133f0(*(uint *)(&DAT_0043d470 + local_8 * 8));
      } while (iVar1 != 0);
    }
    local_8 = local_8 + 1;
  } while( true );
}

