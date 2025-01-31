﻿// <auto-generated> This file has been auto generated by EF Core Power Tools. </auto-generated>
#nullable disable
using System;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;

namespace EFCore_Practice.Database_First_Migration
{
    public partial class testContext : DbContext
    {
        public testContext()
        {
        }

        public testContext(DbContextOptions<testContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Guilds> Guilds { get; set; }
        public virtual DbSet<Items> Items { get; set; }
        public virtual DbSet<Players> Players { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Guilds>(entity =>
            {
                entity.HasKey(e => e.GuildId);
            });

            modelBuilder.Entity<Items>(entity =>
            {
                entity.HasKey(e => e.ItemId);

                entity.HasIndex(e => e.OwnerId)
                    .IsUnique();

                entity.Property(e => e.CreatedDate).HasDefaultValueSql("(getutcdate())");

                entity.HasOne(d => d.Owner)
                    .WithOne(p => p.Items)
                    .HasForeignKey<Items>(d => d.OwnerId);
            });

            modelBuilder.Entity<Players>(entity =>
            {
                entity.HasKey(e => e.PlayerId);

                entity.HasIndex(e => e.GuildId);

                entity.HasIndex(e => e.Name)
                    .HasName("Index_Player_Name")
                    .IsUnique()
                    .HasFilter("([Name] IS NOT NULL)");

                entity.HasOne(d => d.Guild)
                    .WithMany(p => p.Players)
                    .HasForeignKey(d => d.GuildId);
            });

            OnModelCreatingPartial(modelBuilder);
        }

        partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
    }
}