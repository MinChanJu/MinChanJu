package com.example.CRUD.model;

import java.time.LocalDateTime;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.PrePersist;
import jakarta.persistence.Table;

@Entity
@Table(name = "user_table")
public class User {
    
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private long id;
    private LocalDateTime createdAt;
    private String userName;
    private String userPw;
    private String phoneNumber;

    @PrePersist
    public void onCreate() {
        this.createdAt = LocalDateTime.now();
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(LocalDateTime createdAt) {
        this.createdAt = createdAt;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }
    
    public String getUserPw() {
        return userPw;
    }
    
    public void setUserPw(String userPw) {
        this.userPw = userPw;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
}
